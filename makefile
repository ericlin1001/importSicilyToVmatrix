all:
	./genProblem.py
	#./genProblem.py "/home/ailab/tmplink/importSicilyToVmatrix/working/transform/unzip/2348 - STL/1005" "/home/ailab/tmplink/importSicilyToVmatrix/working/transform/problems/2348 - STL/1005.json" "Testing::"
	#./genProblem.py "/home/ailab/tmplink/importSicilyToVmatrix/working/transform/unzip/2311 - Polymorphism/1004" "/home/ailab/tmplink/importSicilyToVmatrix/working/transform/problems/2311 - Polymorphism/1004.json"  "From Sicily::2311 - Polymorphism::1004::"


# 1. first copy all files, and unzip in unzip/
# 2. You may , change the cookes set by creat.sh
# to import all from unzip
genALL:
	./transToJson.sh
