#include "stdafx.h"
#include "Dib.h"
#define DIB_HEADER_MARKER ((WORD)'M' << 8 | 'B')

BOOL CDib::LoadBMP(LPCTSTR lpszFileName)
{
	//file���� ���� ��, lpszFileName�� �̸��� ���� ������ ���� ���� �˻��ϴ� ��.
	CFile	file;

	if( !file.Open(lpszFileName,
		CFile::modeRead | CFile::shareDenyWrite ))
		return FALSE;

	//���������� ������ ������ �� ����. BITMAPINFOHEADER��ŭ�� ���̸� �о� ���̰�, ó�� 2����Ʈ�� 'BM'���� Ȯ���ϴ� ��
	//'BM'�� �ƴ϶�� �������� BMP�����̶� ������ �ʴ´�.
	BITMAPFILEHEADER	bmfh;
	if( file.Read((LPSTR)&bmfh, sizeof(BITMAPFILEHEADER)) != sizeof(BITMAPFILEHEADER)) //���Ͽ��� sizeof(BITMAPFILEHEADER)��ŭ�� ũ�⸦ 
	{																				   //�о� &bmfh�� �Ҵ�
		file.Close();
		return FALSE;
	}
	
	if( bmfh.bfType != DIB_HEADER_MARKER )
	{
		file.Close();
		return FALSE;
	}

	//DIB������ ũ�⸦ ���.
	UINT nFileSize, nDibSize;
	nFileSize	= (UINT)file.GetLength();  //BITMAPFILEHEADER + BITMAPINFOHEADER + �������̺� + �ȼ�������
	nDibSize	= nFileSize - sizeof(bmfh);//BITMAPINFOHEADER + �������̺� + �ȼ�������

	//m_pDib�� �޸𸮸� �Ҵ��ϰ� Dib������ ����� �߰�
	if( m_pDib ) Destroy();
	m_pDib = new BYTE[nDibSize];
	if( m_pDib == NULL )
	{
		file.Close();
		return FALSE;
	}

	if( file.Read(m_pDib, nDibSize) != nDibSize)//���Ͽ��� nDibSize��ŭ�� ũ�⸦ ���� �� m_pDib�� �Ҵ�.
	{
		delete [] m_pDib;
		m_pDib	= NULL;
		file.Close();
		return FALSE;
	}

	//BITMAPINFOHEADER�� biSize �ʵ带 Ȯ���Ͽ� �̰��� �Ϲ����� �������� ��Ʈ���� �´����� Ȯ��.
	LPBITMAPINFOHEADER lpbmi = (LPBITMAPINFOHEADER)m_pDib;
	if( lpbmi->biSize != sizeof(BITMAPINFOHEADER) )
	{
		delete [] m_pDib;
		m_pDib	= NULL;
		file.Close();
		return FALSE;
	}

	////////////////////////////////////////////////////////////////////////////////////////////
	//���ݱ����� DIB�� ������ CDib ��ü ���η� �о� ���̰� �������� ���������� Ȯ���Ͽ���./////
	////////////////////////////////////////////////////////////////////////////////////////////

	//��������� ���� ����//
	InitDib();

	//��� ���� �Ϸ�.
	file.Close();

	return TRUE;
}

BOOL CDib::SaveBMP(LPCTSTR lpszFileName)
{
	CFile	file;
	BITMAPFILEHEADER    bmfh;

	// DIB ��ü�� �����ϰ� ���� ������ FALSE�� ��ȯ.
	if( m_pDib == NULL )
		return FALSE;

	// ���� ���� ���� ����
	if( !file.Open(lpszFileName, CFile::modeCreate | CFile::modeWrite | 
		CFile::shareDenyWrite) )
		return FALSE;

	// BITMAPFILEHEADER ��� ���� ����
	bmfh.bfType      = DIB_HEADER_MARKER;	// �׻� "BM"
	bmfh.bfSize		 = (DWORD)sizeof(BITMAPFILEHEADER) + m_nDibSize;
	bmfh.bfReserved1 = 0;		// �׻� 0
	bmfh.bfReserved2 = 0;		// �׻� 0
	bmfh.bfOffBits	 = (DWORD)(sizeof(BITMAPFILEHEADER) 
		+ sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*GetPaletteNums());

	// BITMAPFILEHEADER ���� 
	file.Write((LPSTR)&bmfh, sizeof(bmfh));

	// DIB ����(BITMAPINFOHEADER + ���� ���̺� + �ȼ� ������) ����
	file.Write(m_pDib, m_nDibSize);

	// ���� �ݱ�
	file.Close();

	return TRUE;
}