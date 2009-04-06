#pragma once

class RGBBYTE;
class CDib
{
public:
	CDib(void);
	CDib(const CDib& dib);
	~CDib(void);
protected:
	LONG			m_nWidth; //�̹��� ����ũ��
	LONG			m_nHeight;//�̹��� ����ũ��
	WORD			m_nBitCount;//�ȼ��� ��Ʈ��
	DWORD		m_nDibSize;	//Dib������
	BYTE*			m_pDib;		//Dib ������ ���� �ּ�
	BYTE**		m_pPtr;		//�׷��� ������ �̹������� 2D �ȼ� ���ٿ� ������
	RGBBYTE**	m_pRgbPtr;	//Ʈ���÷� �̹������� 2D�ȼ� ���ٿ� ������	

public:
	BOOL CreateGrayImage(int nWidth, int nHeight, BYTE value = 255);
	bool CreateRGBImage(int nWidth, int nHeight, COLORREF value = 0x00ffffff);
	void Destroy(void);

	//ġȯ ������ �����ε��� �̹��� ����.
	CDib& operator = (const CDib& dib);

protected:
	BOOL InitDib(void);
public:
	BOOL			Load(LPCTSTR lpszFileName);
	BOOL			Save(LPCTSTR lpszFileName);
	
	BOOL			LoadBMP(LPCTSTR lpszFileName);
	BOOL			SaveBMP(LPCTSTR lpszFileName);
	//BITMAP���� ���� �Լ�///////////////////////////////////////////////////
	LONG			GetHeight(void)			{ return m_nHeight;			}
	LONG			GetWidth(void)			{ return m_nWidth;			}
	WORD			GetBitCount(void)		{ return m_nBitCount;		}
	DWORD			GetDibSize(void)		{ return m_nDibSize;		}
	BOOL			IsValid(void)			{ return (m_pDib != NULL);	}
	
	//m_pDib �����͸� BITMAPINFO* Ÿ������ ����ȯ�ؼ� ��ȯ�Ѵ�.
	LPBITMAPINFO	GetBitmapInfoAddr()	{ return (LPBITMAPINFO)m_pDib;}
	
	//�ȷ�Ʈ���� RGBQUAD �迭�� ������ ��ȯ.
	int				GetPaletteNums(void);	
	
	// �ȼ� ������ ���� ������ ��ȯ.
	LPVOID			GetDibBitsAddr(void);

	void Draw(HDC hDC);
	void Draw(HDC hDC, int dx, int dy);
	void Draw(HDC hDC, int dx, int dy, int dw, int dh, DWORD dwRop = SRCCOPY);
	void Draw(HDC hDC, int dx, int dy, int dw, int dh, int sx, int sy, int sw, int sh, DWORD dwRop = SRCCOPY);

	BOOL Copy(CDib* pDib);
	BOOL AllocPtr(void);
	void FreePtr(void);
	
	
	BYTE**		GetPtr(void);
	RGBBYTE**	CDib::GetRGBPtr(void);
};

inline BYTE**	CDib::GetPtr()
{
	ASSERT(m_nBitCount == 8);
	ASSERT(m_pPtr != NULL);

	return m_pPtr;
}
inline RGBBYTE** CDib::GetRGBPtr()
{
	ASSERT(m_nBitCount == 24);
	ASSERT(m_pRgbPtr != NULL);

	return m_pRgbPtr;
}

template<typename T>
inline T limit(const T& value)
{
	return ( (value > 255) ? 255 : ((value < 0) ? 0 : value));
}
template<typename T>
inline T limit(const T& value, const T& lower, const T& upper)
{
	return ((value > upper) ? upper : ((value < lower) ? lower : value));
}
template<typename T>
inline void swap( T& left, T& right )
{
	T tmp = left;
	left = right;
	right = tmp;
}