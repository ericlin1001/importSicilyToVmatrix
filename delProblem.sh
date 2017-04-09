problemID=1641
if [ -z $1 ]; then
	problemID=1641
	echo "Please ./delProblem.sh [problemID]"
	exit;
else
	problemID=$1
fi
curl "https://vmatrix.org.cn/api/libraries/26/problems/$problemID" -X "DELETE"  -H "Host: vmatrix.org.cn" -H "User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:52.0) Gecko/20100101 Firefox/52.0" -H "Accept: application/json, text/plain, */*" -H "Accept-Language: zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3" --compressed -H "Referer: https://vmatrix.org.cn/library/26/problem?pageId=1" -H "Cookie: matrix-session-id=s%3AnjsRc6IoGTWFkJEBixS8g95_8KmzFLUW.rh6BTufzQUATa1qH2gV09W6SAJDTPkmnz49X%2BoTvk3Y" -H "Connection: keep-alive"
