def TowerOfHanoi(disks , initialRod, finalRod, tempRod):
    if disks==1:
        print ("disk 1 from initialRod",initialRod,"to finalRod.",finalRod)
        return
    TowerOfHanoi(disks-1, initialRod, tempRod, finalRod)
    print ("disk",disks,"from initialRod",initialRod,"to finalRod.",finalRod)
    TowerOfHanoi(disks-1, tempRod, finalRod, initialRod)

disks = 4
TowerOfHanoi(disks,'Disk 1','Disk 2','Disk 3')