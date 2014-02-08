// law.h : main header file for the LAW application
//

#if !defined(AFX_LAW_H__777D38AC_7F02_468C_8BA3_6938AA066ABD__INCLUDED_)
#define AFX_LAW_H__777D38AC_7F02_468C_8BA3_6938AA066ABD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLawApp:
// See law.cpp for the implementation of this class
//
	typedef unsigned long _U32;
		typedef signed long _S32;
		typedef unsigned short _U16;
		typedef signed short _S16;
		typedef unsigned long _U32;
		typedef signed long _S32;
		typedef unsigned short _U16;
		typedef	signed short _S16;
		typedef struct ext3_dir_entry {
			_U32	inode;			/* Inode number */
			_U16	rec_len;		/* Directory entry length */
			BYTE	name_len;		/* Name length */
			BYTE	file_type;
			char	name[255];	/* File name */
		}dir;
		typedef struct ext2_group_desc{
			_U32	bg_block_bitmap;		/* Blocks bitmap block */
			_U32	bg_inode_bitmap;		/* Inodes bitmap block */
			_U32	bg_inode_table;			/* Inodes table block */
			_U16	bg_free_blocks_count;	/* Free blocks count */
			_U16	bg_free_inodes_count;	/* Free inodes count */
			_U16	bg_used_dirs_count;		/* Directories count */
			_U16	bg_pad;
			_U32	bg_reserved[3];
		}group;
		
		typedef struct ext2_inode {
	_U16	i_mode;		/* File mode */
	_U16	i_uid;		/* Low 16 bits of Owner Uid */
	_U32	i_size;		/* Size in bytes */
	_U32	i_atime;	/* Access time */
	_U32	i_ctime;	/* Creation time */
	_U32	i_mtime;	/* Modification time */
	_U32	i_dtime;	/* Deletion Time */
	_U16	i_gid;		/* Low 16 bits of Group Id */
	_U16	i_links_count;	/* Links count */
	_U32	i_blocks;	/* Blocks count */
	_U32	i_flags;	/* File flags */
	union {
		struct {
			_U32  l_i_reserved1;
		} linux1;
		struct {
			_U32  h_i_translator;
		} hurd1;
		struct {
			_U32  m_i_reserved1;
		} masix1;
	} osd1;				/* OS dependent 1 */
	_U32	i_block[15];/* Pointers to blocks */
	_U32	i_generation;	/* File version (for NFS) */
	_U32	i_file_acl;	/* File ACL */
	_U32	i_dir_acl;	/* Directory ACL */
	_U32	i_faddr;	/* Fragment address */
	union {
		struct {
			BYTE	l_i_frag;	/* Fragment number */
			BYTE	l_i_fsize;	/* Fragment size */
			_U16	i_pad1;
			_U16	l_i_uid_high;	/* these 2 fields    */
			_U16	l_i_gid_high;	/* were reserved2[0] */
			_U32	l_i_reserved2;
		} linux2;
		struct {
			BYTE	h_i_frag;	/* Fragment number */
			BYTE	h_i_fsize;	/* Fragment size */
			_U16	h_i_mode_high;
			_U16	h_i_uid_high;
			_U16	h_i_gid_high;
			_U32	h_i_author;
		} hurd2;
		struct {
			BYTE	m_i_frag;	/* Fragment number */
			BYTE	m_i_fsize;	/* Fragment size */
			_U16	m_pad1;
			_U32	m_i_reserved2[2];
		} masix2;
	} osd2;				/* OS dependent 2 */
}inode;



class CLawApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CLawApp();
		unsigned long BlocksPerGroup,InodesPerGroup,BlocksCount;
		//dir *d[8000];
		group *GDesc[129];
		//int cnt;
		int Next2Dirs(dir *d[],int DirNum,char ReadBuf[],int Offset);
		void GetGds(group *GDesc[],int GDNum,char ReadGD[],int Offset);
		HANDLE dsk;
		hyper QuadOff,BlockSize;
				union {
					hyper quad;
					struct {
						DWORD low;
						LONG high;
					};
				} num;
		
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLawApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAW_H__777D38AC_7F02_468C_8BA3_6938AA066ABD__INCLUDED_)
