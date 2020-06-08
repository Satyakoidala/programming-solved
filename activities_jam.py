def activities(l,n):
	ip=l.copy()
	l.sort()
	ans='C'
	C=True
	C_endtime=l[0][-1]
	J=False
	J_endtime=0
	endtime=l[0][-1]
	for i in range(1,n):
		if l[i][0]>=C_endtime:
			C=False
			C_endtime=0
		if l[i][0]>=J_endtime:
			J=False
			J_endtime=0
		if endtime>l[i][0] :
			if C and J:
				return 'IMPOSSIBLE'
			if C:
				ans+='J'
				J=True
				J_endtime=l[i][-1]
			elif J:
				ans+='C'
				C=True
				C_endtime=l[i][-1]
			elif not C and not J:
				ans+='C'
				C=True
				C_endtime=l[i][-1]
		else:
			if ans[-1]=='C':
				C=True
				C_endtime=l[i][-1]
			elif ans[-1]=='J':
				J=True
				J_endtime=l[i][-1]
			ans+=ans[-1]
		endtime=l[i][-1]

	res={}
	for x,y in zip(l,list(ans)):
		if x in res:
			res[x].insert(0,y)
		else:
			res[x]=[y]
	ans=''
	for item in ip:
		ans+=res[item].pop()
	return ans

t=int(input())
for i in range(1,t+1):
	n=int(input())
	ip=[]
	for _ in range(n):
		ip.append(tuple(map(int,input().split())))
	print('Case #'+str(i)+': '+str(activities(ip,n)))
	