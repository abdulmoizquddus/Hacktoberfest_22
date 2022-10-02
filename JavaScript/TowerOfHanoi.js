const tower = (n, rod_initial,  rod_final,  rod_temp) =>{
        if (n == 0)
        {
            return;
        }
        tower(n - 1, rod_initial, rod_temp, rod_final);
        console.log("disk " + n + " initial rod " + rod_initial +
        " final rod " + rod_final);
        tower(n - 1, rod_temp, rod_final, rod_initial);
}

const disks = 3;
     
tower(disks, 'Disk 1', 'Disk 2', 'Disk 3');