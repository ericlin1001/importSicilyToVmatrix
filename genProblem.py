#!/usr/bin/python3
import json
import os
import subprocess
import sys
import shlex

import ast 
import codecs
def myEscape(s):
    #return s.decode("string_escape");
    #es = codecs.decode(s,  "unicode_escape");
    return s;
    return es[0];

def setupProblem(data,  title,  desp, maincpp,  inouts, framework):
    data["title"]   =  title;
    data["description"] = desp;
    #
    # in/out
    num = 0;
    inFiles = [];
    outFiles = [];
    for i in inouts:
        namein = "standard_input" + str(num);
        nameout = "standard_output" + str(num);
        inFiles.append(namein);
        outFiles.append(nameout);
        data["files"]["standard_input"][namein] = i[0];
        data["files"]["standard_output"][nameout] = i[1];
        num = num + 1;
    data["config"]["standard"]["standard_input"] = inFiles;
    data["config"]["standard"]["standard_output"] = outFiles;

    # main.cpp
    # framework
    if framework !=  "":
        data["config"]["standard"]["support"] =  ["framework.cpp"];
        data["files"]["support"]["framework.cpp"] = framework.replace("source.cpp",  "source.h");
        data["files"]["submission"]["source.h"] = maincpp;
        data["config"]["submission"] = ["source.h"];
    else:
        data["config"]["submission"] = ["source.cpp"];
        data["files"]["submission"]["source.cpp"] = maincpp;
        data["config"]["standard"]["support"] =  [];
    return data;

def defineProblem(data):
    data["title"]   =  "Hello world! This should pass2!. Testing  - title-  From python";
    data["description"] = "testing description- from python";
    #
    data["config"]["standard"]["standard_input"] = ["standard_input0",  "standard_input1"];
    data["config"]["standard"]["standard_output"] = ["standard_output0", "standard_output1"];
    data["config"]["standard"]["support"] =  ["framework.cpp", "framework2.cpp"];
    #
    data["files"]["submission"]["main.cpp"] = "#include<iostream>\nusing namespace std; int main(){ \n\tcout<<\"correct answer\"; return 0;\n}";
    #

    #input ouput.
    data["files"]["standard_input"]["standard_input0"] = "input0 from python";
    data["files"]["standard_input"]["standard_input1"] = "input1 from python";
    data["files"]["standard_output"]["standard_output0"] = "correct answer";
    data["files"]["standard_output"]["standard_output1"] = "correct answer";
    data["files"]["support"]["framework.cpp"] = "//useless,  test from python";
    data["files"]["support"]["framework2.cpp"] ="//useless,  test from python";
    return data;



def isFile(file):
    return os.path.isfile(file);

def getInitData():
    file = open('./original.json',  'r');
    data = json.load(file);
    return data;

def getStrFromJson(data):
        return json.dumps(data)

def writeToFile(s,  file):
    with open(file,  'w') as f:
        f.write(s);
        f.close();
    if not isFile(file):
        printf("Error: Can't generate file: "  +  file);

def writeOutData(data,  file):
    outFile = file;
    with open(file,  'w') as f:
        json.dump(data, f);
    if not isFile(file):
        printf("Error: Can't generate file: "  +  file);

def submitFile(file):
    createCmd = './create.sh \"' + file + "\"";
    print("Runing: " + createCmd);
    os.system(createCmd);

def readInFile(file):
    file = open(file,  'r');
    return file.read();



def main():
    # in srcDir:
    # metadata.json,  .DIR main.cpp,  [framework.cpp],  
    if len(sys.argv) < 4:
        print("./genProblem.py [src - directory] [saveFile] [prefix]");
        exit(0);
    srcDir = sys.argv[1];
    saveFile = sys.argv[2];
    prefix = sys.argv[3];
    #
    metadata = srcDir  + "/metadata.json";
    inouts = srcDir  + "/.DIR";
    maincpp = srcDir  + "/main.cpp";
    framework =srcDir  + "/framework.cpp"; 
    if not isFile(metadata):
        print("Error: Can't find file: " +  metadata);
    if not isFile(framework):
        frameworkContent = ""
    else:
        frameworkContent = readInFile(framework);

    meta = json.loads(myEscape(readInFile(metadata)));
    # Parse title.
    title = prefix + meta["title"];
    # parse description
    desp = ""
    desp = desp + "# Description\n" + meta["description"] + "\n";
    desp = desp + "# Input\n" + meta["input"]+ "\n";
    desp = desp + "# Output\n" + meta["output"]+ "\n";
    desp = desp + "# Sample_Input\n```\n" + meta["sample_input"] + "\n```"+ "\n";
    desp = desp + "# Sample_Ouput\n```\n" + meta["sample_output"] + "\n```"+ "\n";
    desp = desp + "# Hint\n" + meta["hint"] + "\n";
    #desp = ast.literal_eval(desp);
    #desp = desp.decode('unicode_escape');
    # parse in/out
    inoutContents = [];
    inoutFiles = readInFile(inouts);
    inoutArr = inoutFiles.split('\n');
    for  i in inoutArr:
        if i  ==  "":
            continue;
        k = i.split(' ');
        if len(k)  != 2:
            print("Error: when parsing file:"  + inouts);
            return;
        f1 = srcDir + "/" + k[0];
        f2 = srcDir + "/" + k[1];
        if not isFile(f1):
            print("Error: Can't find file:"  + f1  +  ", require by "  + inouts );
        if not isFile(f2):
            print("Error: Can't find file:"  + f2+  ", require by "  + inouts );
        oneInout = [ readInFile(f1),  readInFile(f2)];
        inoutContents.append(oneInout);

    data = getInitData();
    data = setupProblem(data, title,  desp, readInFile(maincpp), inoutContents , frameworkContent  );
    if frameworkContent ==  "":
        writeOutData(data, saveFile);
    else:
        s = getStrFromJson(data);
        s = s.replace("CODE_FILES", "framework.cpp");
        writeToFile(s,  saveFile);
    #
    submitFile(saveFile);




def test():
    data = getInitData();
    data = setupProblem(data, "test2 - my title",  "simple descript", "and basic  main.cpp", [["in","out1"], ["in2", "out2"]] , "thisis a framework"  );

    writeOutData(data, "data.json");
    submitFile("data.json");

main();

