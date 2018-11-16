//////////////////////////////////////////////////////////////////////
// PckClass.cpp: ���ڽ����������繫˾��pck�ļ��е����ݣ�����ʾ��List��
// �й���ĳ�ʼ����
//
// �˳����� �����/stsm/liqf ��д��pck�ṹ�ο���ˮ��pck�ṹ.txt����
// �ο����������Դ����в��ڶ�pck�ļ��б��Ĳ���
//
// �˴���Ԥ�ƽ��ῪԴ���κλ��ڴ˴�����޸ķ����뱣��ԭ������Ϣ
// 
// 2012.4.10
//////////////////////////////////////////////////////////////////////

#include "PckClass.h"

#pragma warning ( disable : 4996 )
#pragma warning ( disable : 4146 )
#pragma warning ( disable : 4267 )

CPckClass::CPckClass(LPPCK_RUNTIME_PARAMS inout)
{
	m_lpPckParams = inout;
}

CPckClass::~CPckClass()
{}

BOOL CPckClass::Init(LPCTSTR	szFile)
{
	_tcscpy(m_PckAllInfo.szFilename, szFile);
	GetFileTitle(m_PckAllInfo.szFilename, m_PckAllInfo.szFileTitle, MAX_PATH);

	if(!MountPckFile(m_PckAllInfo.szFilename)) {

		ResetPckInfos();

		return FALSE;
	} else {

		BuildDirTree();
		return (m_PckAllInfo.isPckFileLoaded = TRUE);
	}
}