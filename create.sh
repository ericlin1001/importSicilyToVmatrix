cookies="s:8uMuvFGVmuasIeqM4TPOWlzgMNdDQsFl.dlror4Lh5AfR/cA7tytOdevjH7WAhCztOnNh6Y6JLSQ"
data=$1

if [ ! -f "$data" ]; then
	data="./default.json"
	echo "Can't find file:$data, Using default.json";
fi
isDebug=false

if $isDebug; then
curl "https://vmatrix.org.cn/api/libraries/26/problems" -H "Host: vmatrix.org.cn" -H "User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:52.0) Gecko/20100101 Firefox/52.0" -H "Accept: application/json, text/plain, */*" -H "Accept-Language: zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3" --compressed -H "Content-Type: application/json;charset=utf-8" -H "Referer: https://vmatrix.org.cn/library/26/problem/programming?problemId=-1&pageId=1" -H "Cookie: matrix-session-id=$cookies" -H "Connection: keep-alive" -d "@$data" -v
else 
curl "https://vmatrix.org.cn/api/libraries/26/problems" -H "Host: vmatrix.org.cn" -H "User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:52.0) Gecko/20100101 Firefox/52.0" -H "Accept: application/json, text/plain, */*" -H "Accept-Language: zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3" --compressed -H "Content-Type: application/json;charset=utf-8" -H "Referer: https://vmatrix.org.cn/library/26/problem/programming?problemId=-1&pageId=1" -H "Cookie: matrix-session-id=$cookies" -H "Connection: keep-alive" -d "@$data" 2>&1  |tail -n1
fi
echo "\nFinished!"
