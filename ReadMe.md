
-------------------------------------------------------------------------------------------------


				LAW Version 1.0.0.1.0.2
	
					Readme

-------------------------------------------------------------------------------------------------




	I.   Introduction
	II.  System Requirements
	III. How to use LAW
	IV.  Additional Features
	V.   FAQ's	
	VI.  Contact Us




1. Introduction
   ------------
	
	LAW is an acronym for Linux Access from Windows. Its a tool resembling Windows Explorer, only difference being that LAW is meant for Linux filesystems. Using LAW , one can access Linux Filesystems in a Read-Only fashion. i,e. One can explore through the entire Linux Filesystem and view all the files present in the different directories of the tree structured filesystem.


2. System requirements
   -------------------


	>> Any Windows NT based OS (Win XP,Win 2000,Win NT)

	>> LINUX OS (with single partition)


3. How to use LAW..
   -----------------
	

	LAW works exactly like Windows Explorer. The main window is split into two panes, the left one and the right one. The left one in LAW ,unlike Windows Explorer ,does not show any drives present on ur system but actually shows the "ROOT" of the Linux Filesystem , denoted by "/" . Under it are present the different directories , which differs from system to system. 


	The right pane reflects the contents of the selected directory in the left pane. Linux has around 7 different kinds of files and extensions are not considered here , although they can be a part of your filename. The main types of files are :

			1 . Regular File
			2 . Directory file
			3 . Device file	
			4 . Symbolic Link file

	These different files are represented by different icons. The details of icon association are presented in the File Menu.



4. Additional Features
   -------------------  

	
	4.1  File Properties
	     ---------------

		A right mouse click on the right pane in the main window displays a pop-up menu which contains an option called File Properties. This displays a Dialog Box containing various details. Although there are numerous pieces of information about a file maintained in the Linux Filesystem , we felt that these are the most required from a Windows User's perspective.
Note that the mouse must be clicked on a file to display its properties.


	4.2 Export File
 	    -----------

		The second option present in the pop-up menu is the "export file". This is used if you want to transfer a file from the Linux Partition to your Windows partition. LAW currently supports file transfer of sizes upto 4 GB. This option also requires that a file be selected obviously. One can copy a file of his or her choice to any location in the Windows partition provided there is enough disk space available.




5. FAQ's
   -----

	
	Q : Will this work on any OS?

	A : No. Currently it has been developed to work only on Win NT based Operating Sytems.

	Q : Why doesn't it work on other Operating systems?
	
	A : Because the handling of a Hard Disk is different in non Win-NT systems. 

	Q : I get an error when i execute this LAW. What do i do?	

	A : Ensure that the following hold before running LAW :
		
		1 . You are logged in as ADMINISTRATOR

		2 . You have ,the DLL's provided alongwith the application, in either the current 		    directory or your system directory.

	Q : Are the DLL's absolutely necessary?

	A : Yes. If you dont have Visual Studio installed then they are a must. If you already 	  	    have Visual Studio installed on your system , then they are not required.


	Q : The application hangs if I click on the "dev" directory.What do i do?

	A : The application hasn't actually hung at that point. On the contrary , it is working a     	    lot. Its just that the "dev" directory has a lot of files which it has to read and 	    	    display(usually aorund 8000 objects!!! imagine Windows Eplorer trying to open a 	  	    folder with so many objects!!!). So just wait patiently for a while , while LAW looks 	    for ur requested files!!! 


6 . Contact Us
    ----------

	This is still a developing product. Many features can still be added to this application. We need your suggestions to improve this product to make it a full fledged Linux Tool. We look forward to your suggestions so that we can deliver a better product. Although this product has been tested rigorously , there are bound to be some mistakes and errors. Please report any exceptions , errors or bugs noticed during usage to any of the following email addresses and we will certainly get back to you :

		s_murally@yahoo.com

		hvgirish@yahoo.co.in

		zipschumi@yahoo.com

		latha_prakar@yahoo.co.in


	Happy Exploring!!!!!			
