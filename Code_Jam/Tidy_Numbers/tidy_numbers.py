def readCases(fileName):
	inputFile=open(fileName,'r')
	cases=inputFile.readline()
	cases=int(cases)
	return cases

def readNumbers(fileName,cases):
	inputFile=open(fileName,'r')
	number=inputFile.readline()
	for i in range(cases):	
		number=inputFile.readline()
	return int(number)

def main():
	cases=readCases('B-large-practice.in')
	for i in range(1,cases+1):
		number_list=[]
		s=" "
		number=readNumbers('B-large-practice.in',i)
		copy=number
		while copy//10!=0:
			last_digit=copy%10
			number_list.append(last_digit)
			copy=copy//10
		number_list.append(copy)
		number_list.reverse()

		flag=True
		if number//10 ==0:
			print("Case #{i}: {number}".format(i=i,number=number))
			continue

		for z in range(len(number_list)-1):
			if number_list[z]>number_list[z+1]:
				if flag==False:
					number_list[rem]-=1
					for j in range(rem+1,len(number_list)):
						number_list[j]=9
					break
				else:
					number_list[z]-=1
					for j in range(z+1,len(number_list)):
						number_list[j]=9
					break
			elif number_list[z]==number_list[z+1] and flag==True:
				rem=z
				flag=False
			elif number_list[z]<number_list[z+1]:
				flag=True

		for j in range(len(number_list)):
			s+=str(number_list[j])
		
		tidy_number=int(s)
		print("Case #{i}: {number}".format(i=i,number=tidy_number))
		number_list.clear()


if __name__ == '__main__':
	main()

