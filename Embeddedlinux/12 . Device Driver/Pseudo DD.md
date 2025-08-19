``` cpp
/*
static int __init firstDD_init(void)
static void __exit firstDD_exit(void)

    These are the basic functions that makes the whole thing 
    The (static int __init firstDD_init(void)) function is used to 
    init the device and use it since it introduce an environmet for the user to interact with diferrent devices

    The (static void __exit firstDD_exit(void)) function is used to 
    deinit the device  

steps :
1 - Allocate the device number major & minor -> device number used to deal with the driver
    Using alloc_chrdev_region finction to indicate the available  major number and link the device driver to it 
    There is an automatic way and manual way (auomatic is preffered)

1 - Register the device to be added in file /proc/devices using function 
    -> register_chrdev   |->automatic way

2 - Define the device as character or block or network
    There are two functions used for that purose 
    cdev_init -> used to prepare the device to be used in the second function
    cdev_add  -> used to add the device 

3 - Generate the file  ( class - device ) to deal with the device like read, write 
    device_create function is used to creat a class that contain the attributed of the device like PWM etc   

-----------------------------------------------------------------------------------------------------------------------------------
After that the static void __exit firstDD_exit(void) contain the destroying fnction used to destroy the device file created and all of it's data in the rfs

    cdev_del(&testdevice);
    device_destroy(my_class ,device_number);
    class_destroy(my_class);
    unregister_chrdev_region(device_number ,1);     //automatic way



Then call these two functions for execution 
module_init(firstDD_init);
module_exit(firstDD_exit);

*/


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* 
struct cdev testdevice -> declaired in cdev.h used in cdev_init to make the device ready to add to the system with cdev_add(). 
struct class *my_class -> declared in class.h used in device_create (device_create - creates a device and registers it with sysfs) 
struct device *mydevice -> a pointer of the type that the device_creat retrns
dev_t device_number -> the device major number
*/

#include <linux/module.h>          //for modules
#include <linux/init.h>     //for mod init and exit
#include<linux/moduleparam.h>   //for passing parameters
#include<linux/fs.h>    //for regesteration for manor number *under major*
#include<linux/cdev.h>  //for making the device file automatically
//#include <linux/gpio.h>
//#include<linux/pwm.h>
//#include<linux/kernel.h>


//Meta data
MODULE_LICENSE("GPL");
MODULE_AUTHOR("BIRG16");
MODULE_DESCRIPTION("DD");

// #define LED 2
// #define Button 3

#define SIZE  255
#define SIZE_READ 3

int number = 0;
int major_number = 0;
static unsigned char buffer[SIZE] = "";




dev_t device_number;
struct cdev  testdevice ;
struct class *my_class;
struct device * mydevice;



//used to path parameters while making the mod (insmod)
//            parameter     data type   permissions
module_param(   number,            int,        0774);
// MODULE_PARM_DESC(number,"major number");








// This function is included in fs.h 
//This function is a pointer member in file_operations structure used to open a file for the device driver
//int (*open) (struct inode *, struct file *);

static int driver_open(struct inode * device_file, struct file * instance) 
{
    printk("%s file opened\n" , __FUNCTION__);
    return 0;
}

// This function is included in fs.h
//This function is a pointer member in file_operations structure used to close a file for the device driver
//int (*release) (struct inode *, struct file *);
static int driver_close(struct inode * device_file, struct file * instance) 
{
    printk("%s file closed\n" , __FUNCTION__);
    return 0;
}



// ssize_t driver_write (struct file * file , const char __user  *user_buffer, size_t count, loff_t *offs)
// {
//     int not_copied;
//     /*Get amunt of data to copy*/
//     //to copy = min(count, buffer_pointer);
//     printk("%s : the count to write %ld \n", __func__,count);
//     printk("%s : the offs %lld \n",__func__,*offs);
//     if(count + *offs > SIZE)
//     {
//         count = SIZE - *offs;
//        // count = 0;
//            //printk("The count now equal in write : %ld" , count);

//     }
//     if(!count) 
//     {
//         printk("no space left\n");
//         return -1;
//     }
//     not_copied = copy_from_user(&buffer[*offs],user_buffer,count);
//     if(not_copied)
//     {
//         return -1;
//     }
  
//     switch (buffer[0])
//     {
//     case 1:

//         gpio_set_value(LED,1);
//         break;
//     case 0:
//         gpio_set_value(LED,0);
//         break;
    
//     default:
//         break;
//     }


//     *offs = count;
//     printk("%s : already done %ld \n",__func__,count);
//     printk("%s : message %s \n",__func__,buffer);
//     return 0;    
// }


ssize_t driver_read (struct file * file , char __user *user_buffer, size_t count, loff_t *offs)
{
    printk("Open called!\n");
    return 0;
    //     int not_copied;
    //     char tmp[SIZE_READ] = "";

    //     /*Get amunt of data to copy*/
    //     //to copy = min(count, buffer_pointer);
    //     printk("%s : the count to read %ld \n", __func__,count);
    //     printk("%s : the offs %lld \n",__func__,*offs);
    //     if(count + *offs > SIZE_READ)
    //     {
    //         count = SIZE_READ - *offs;
    //     }
    //     not_copied = copy_to_user(user_buffer,&buffer[*offs],count);
    //     printk("The value of the button is %d\n",gpio_get_value(Button));
    //     tmp[0]=gpio_get_value(Button) + '0';
    //     tmp[1] = '\n';
    //     not_copied = copy_to_user(user_buffer,&tmp[*offs],count);*/
    //     if(not_copied)
    //     {
    //         return -1;
    //     }
    //     *offs = count;
    //     printk("%s : not copied %d \n",__func__,not_copied);
    //     printk("%s : message %s \n",__func__,user_buffer);
    //     printk("The count now equal in read : %ld" , count);
    //     return count;    
}


//This is a structure defined in fs.h file used for opening files for the device driver 
struct file_operations fops = 
{
    //struct mo dule *owner;
    .owner = THIS_MODULE,       // The owner shuld be assigned to THIS_MODULE 
                                //THIS_MODULE is a flag 
    .open = driver_open,        //The open pointer assaigned to the open function
    .release = driver_close,     //The release pointer assigned to the close function 
    // .read = driver_read,
    // .write = driver_write
};





//Evry device driver creates a file manually or automatically for now this is the manually way
//This file is created using register_chrdev 
//Every device driver has a unique number called major number for every device driver and another subnumber called manor for instances of this device
//register_chrdev returns 0 if the file created successfully and -v if not
//To delet this file unregister_chrdev is used 
static int __init firstDD_init(void)
{
    printk("%d\n", number);
        int retval = 0;
       // major_number = number;//
        printk("Hi Bro\n");
        // 1 - allocate the device number
        //retval = register_chrdev(major_number ,"boooooooooom", &fops);  //manual way

        retval = alloc_chrdev_region(&device_number,0,1,"boooooooooom");      //automatic way
        if(!retval)
        {
            printk("%s  retval = 0  registered device number major = %d  Minor = %d \n" , __FUNCTION__ , MAJOR( major_number) , MINOR(major_number));
        }
        else
        {
            printk("ERROR coulden't regester\n");
            return -1;
        }

    //     // 2 - define the device character or block or network

    //         /** character device **/

        cdev_init(&testdevice , &fops);
        retval = cdev_add(&testdevice , device_number , 1);

        if(retval != 0)
        {
            goto ERROR_CHARACTER;
        }

        // 3 - generate the file  ( class - device ) under name boooooooooom
        if((my_class = class_create("class_boooooooooom")) == NULL)  ////used to creat the class device file in /sys/class/
        {
            printk("Device class can not be created!\n");
            goto ERROR_CLASS;
        }

        mydevice = device_create(my_class,NULL,device_number,NULL,"boooooooooom" ); //used to creat the device file in /dev need to change the permissions of that file
                                                                                    //to read and write operations to that file

        if(mydevice == NULL)
        {
            printk("Device class can not be created!\n");
            goto ERROR_DEVICE;
        }

        printk("Device driver is created\n");

    //     if(gpio_request(LED,"LED_GREEN"))
    //     {
    //         printk("cannot use this pin\n");
    //         goto ERROR_GPIO;
    // ;
    //     }
    //     if(gpio_direction_output(LED,0))
    //     {
    //         printk("cannot set the direction of this pin\n");
    //         goto ERROR_DIR_LED;
    //     }

    //     if(gpio_request(Button,"BUTTON"))
    //     {
    //         printk("cannot use this pin\n");
    //         goto ERROR_GPIO;
    // ;
    //     }
    //     if(gpio_direction_input(Button))
    //     {
    //         printk("cannot set the direction of this pin\n");
    //         goto ERROR_DIR_Button;
    //     }



    printk("Hi Bro!\n");

    return 0;

    // ERROR_DIR_Button:
    //     gpio_free(Button);
    // ERROR_DIR_LED:
    //     gpio_free(LED);
    // ERROR_GPIO:
    //     device_destroy(my_class ,device_number);
    ERROR_DEVICE:
        class_destroy(my_class);
    ERROR_CLASS:
        cdev_del(&testdevice);
    ERROR_CHARACTER:
        unregister_chrdev_region((device_number) ,1);     //to delete the register number made by alloc_chrdev_region(&device_number,0,1,"boooooooooom"); 
        return -1;
}


static void __exit firstDD_exit(void)
{
 //   gpio_set_value(LED,0);//
 //   gpio_free(LED);//
 //   gpio_free(Button);//

    //unregister_chrdev(major_number,"boooooooooom");   //manual way
    cdev_del(&testdevice);
    // device_destroy(my_class ,device_number);
    // class_destroy(my_class);
    unregister_chrdev_region(device_number ,1);     //automatic way  destroy the file created "boooooooooom"
    
    
    
    printk("Bye Bro!\n");
}



module_init(firstDD_init);
module_exit(firstDD_exit);



//lsmod
//insmod   modprobe
//rmmod
//modinfo
//sudo mknod /dev/my_device_driver c 50 0       used to make a file node  it's name is boooooooooom this file doesn't contain any permissions 
//                                              u will see this behaviour using dmesg i mean opening and closing the file in case the error
//                                              in this case the file has no permissions so i should manipulate it
//                                              if u tried to cat the file (cat /dev/boooooooooom) it will cause you an error but the file will be opened and closed 
/*

Directories

/dev  -> contain all the devices
/var/log/syslog -> contain all dmesgs -> not in this directory need a change
cat /lib/modules/6.1.0-12-amd64/build/Makefile | grep obj-m -> not in this directory need a change
sudo lsmod | grep devicedrive  -> shows my module 
/sys/module/ -> contain the device driver module folder
/sys/module/devicedrive/parameters -> contain the parameters  created in this code (module_param(   number,            int,        0774);) line 69
sudo echo 10 > /sys/module/devicedrive//parameters/<parameter name>  -> used to chane the value of the parameter  ->>> need rout access
/proc/devices  -> contain all the devices in my case boooooooooom with major numbers
/dev -> contain all the devices in my case boooooooooom with major and minor nubers
/sys/class/ -> contain the class of the device in my case class_boooooooooom
/sys/class/<class_boooooooooom>/boooooooooom/  -> contain the attributes of the driver










*/
```


