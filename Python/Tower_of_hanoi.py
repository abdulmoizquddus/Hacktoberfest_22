def Tower(number_of_disks , initial, final, temp_disk):
	if number_of_disks==1:
		print ("Move disk 1 from ",initial,"to ",final)
		return
	Tower(number_of_disks-1, initial, temp_disk, final)
	print ("Move disk",number_of_disks,"from ",initial,"to ",final,"\n")
	Tower(number_of_disks-1, temp_disk, final, initial)
		
number_of_disks = 4
Tower(number_of_disks,'rod1','rod2','temprod')

