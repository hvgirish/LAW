; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLawView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "law.h"
LastPage=0

ClassCount=11
Class1=CLawApp
Class2=CLawDoc
Class3=CLawView
Class4=CMainFrame

ResourceCount=5
Resource1=ID_POPUP
Class5=CLeftView
Class6=CAboutDlg
Resource2=IDD_ABOUTBOX
Resource3=IDD_PROPERTIES
Class7=Cproperties
Resource4=IDR_MAINFRAME
Class8=CLeged
Class9=CProgress
Class10=CSplashWnd
Class11=CPartInfo
Resource5=IDD_LEGEND

[CLS:CLawApp]
Type=0
HeaderFile=law.h
ImplementationFile=law.cpp
Filter=N
LastObject=CLawApp

[CLS:CLawDoc]
Type=0
HeaderFile=lawDoc.h
ImplementationFile=lawDoc.cpp
Filter=N
LastObject=ID_A_REFRESH

[CLS:CLawView]
Type=0
HeaderFile=lawView.h
ImplementationFile=lawView.cpp
Filter=C
LastObject=CLawView
BaseClass=CListView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC



[CLS:CLeftView]
Type=0
HeaderFile=LeftView.h
ImplementationFile=LeftView.cpp
Filter=T
LastObject=IDC_EDIT5
BaseClass=CTreeView
VirtualFilter=VWC

[CLS:CAboutDlg]
Type=0
HeaderFile=law.cpp
ImplementationFile=law.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308481
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_ICONS
Command2=ID_APP_EXIT
Command3=ID_VIEW_TOOLBAR
Command4=ID_VIEW_STATUS_BAR
Command5=ID_APP_ABOUT
Command6=ID_HELP_WHATISLAW
CommandCount=6

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_VIEW_LARGEICON
Command2=ID_VIEW_SMALLICON
Command3=ID_VIEW_LIST
Command4=ID_APP_ABOUT
CommandCount=4

[MNU:ID_POPUP]
Type=1
Class=?
Command1=ID_EXPORTFILE
Command2=ID_A_PROPERTIES
Command3=ID_A_REFRESH
CommandCount=3

[DLG:IDD_PROPERTIES]
Type=1
Class=Cproperties
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308876
Control3=proname,edit,1342245892
Control4=IDC_STATIC,static,1342308864
Control5=prosize1,edit,1342244992
Control6=IDC_STATIC,static,1342308864
Control7=protype,edit,1342244992
Control8=IDC_STATIC,static,1342308864
Control9=permissions,edit,1342244992
Control10=IDC_STATIC,static,1342308864
Control11=inodeno,edit,1342244992
Control12=prosize2,edit,1342244992
Control13=IDC_STATIC,button,1342177287

[CLS:Cproperties]
Type=0
HeaderFile=properties.h
ImplementationFile=properties.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Cproperties

[DLG:IDD_LEGEND]
Type=1
Class=CLeged
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177795
Control3=IDC_STATIC,static,1342177283
Control4=IDC_STATIC,static,1342177283
Control5=IDC_STATIC,static,1342177283
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352

[CLS:CLeged]
Type=0
HeaderFile=Leged.h
ImplementationFile=Leged.cpp
BaseClass=CDialog
Filter=D
LastObject=CLeged
VirtualFilter=dWC

[CLS:CProgress]
Type=0
HeaderFile=Progress.h
ImplementationFile=Progress.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CProgress

[CLS:CSplashWnd]
Type=0
HeaderFile=Splashm.h
ImplementationFile=Splashm.cpp
BaseClass=CWnd

[CLS:CPartInfo]
Type=0
HeaderFile=PartInfo.h
ImplementationFile=PartInfo.cpp
BaseClass=CDialog
Filter=D
LastObject=CPartInfo
VirtualFilter=dWC

