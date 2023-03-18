# using loop

def flat(lis):
	flatList = []
	# Iterate with outer list
	for element in lis:
		if type(element) is list:
			# Check if type is list than iterate through the sublist
			for item in element:
				flatList.append(item)
		else:
			flatList.append(element)
	return flatList

#------------------------------------------------

# using recursion
def flat(lis):
    output = []
    removNestings(lis, output)
    return output

def removNestings(l, output):
	for i in l:
		if type(i) == list:
			removNestings(i)
		else:
			output.append(i)

