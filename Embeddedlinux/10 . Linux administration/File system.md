- All users stored in /etc/passwd
- userID : **root** -> 0 , **system users** -> \[1:1000\[ , **normal users** >=1000 


##### File Hierarechie / Inverted tree

- /        ---> Root file system
	- home   ---> User directory
	- bin       ---> All commands' binaries for normal users  soft link to usr/bin
	- sbin     ---> All commands' binaries for super users  soft link to                                 [usr/sbin]
	- boot    ---> Contain the boot loader + Kernel
	- dev      ---> Representation for the devices as files
	- etc       ---> Configs for all the system users apps proces 
	- lib        ---> Libraries for programs  32bit  soft link to [usr/lib]
	- lib32    ---> Libraries for programs  soft link to [usr/lib32]
	- lib64    ---> Libraries for programs    64bit   soft link to [usr/lib64]
	- libx32  ---> Libraries for programs  soft link to [usr/libx32]
	- media  ---> mount entry for the disk or the removable media
	- mnt      ---> mount floppy disk (old type of disks)
	- opt       ---> May install programs by some vendors 
	- srv       ---> Install application in it by the user
	- proc     ---> Information about the machine processes , hardware                            - Used by the kernel only
	- tmp      ---> Temporary files of the system                                                                  - Used by the apps
	- root     ---> Home directory for root
	- sys      ---> Info about the system exclusive for hardware 
	- usr       ---> Shared data between users
	- var       ---> Variable files  mails , database , logs

##### Short cuts
- ctrl + l
- ctrl + a
- ctrl + e
- ctrl + k
- ctrl + u 

##### Some commands
- useradd , userdel , passwd 
- df -ih  -> disk file system
- ln  -> hard link
- lsblk -> list block
- fdisk -l -> list all disks
- fdisk /dev/sdb -> make partitions
- mkfs.ext4  , mkfs.xfs     /dev/sdb1  ->  make file system
- sudo dd if=/dev/random  of=/dev/sdb bs=14G count=1
- sudo dumpe2fs /dev/sda1 |less
- e2fsck  /dev/sdb1   -> make check on the file system


#### File VS Directory 
- Directory is a special file that points to another file
##### Content of inode for a file
- inode number
- permission 
- owner
- access time 
- creation time
- modification time
- link count
##### Content of inode for a directory
- Content of inode for a file
- Pointers of the file in the directory 
##### MBR -> Master Boot Record
-> size -> 512 byte = 64 PT + 446 Boot Loader + 2 magic number
-->Partition table -> 64 byte 
---> Each partition needs 16 byte
==> 64 / 16 = 4 primary partitions
==> 3 primary + 1 extended (1 , 2 , 3 , 4)
==> Logic partitions  (5 , 6 , 7 , 8 , .........)
--> 

##### Types of disks
-  PATA or IDE
-  SASA
-  SCSI
-  SAS
-  SSD
-  Flash
-  USB
##### Partition types
- Hard disk (PATA) --> disks : hda , hdb , hdc , hdd --> partitions hda : hda1 , hda2 , hda3 , ...
- Sata disk (sasa , scsi , ssd , ....)--> disks : sda, sdb, sdc, sdd --> partitions sda : sda1, sda2, sda3, ......
- Virtual disk --> disks : vda ,vdb , .......