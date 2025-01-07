#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NGAY
{
	int ngay, thang, nam;
}NGAY;
struct HOADON
{
	char maHD[15], tenKH[50], maSP[15];
	int soLuong;
	float gia,thanhTien;
	NGAY ngayHD;
};
//Khai bao ham 
void Nhap_HD (HOADON *a);
void Xuat_HD (HOADON *a);
float Tong_HD (HOADON a[], int n);
void Tim_HD (HOADON a[], int n, char x[]);
void Sap_giam (HOADON a[], int n);
void Xuat_DSHD (HOADON a[], int n);
int main()
{
	int n;
	char path [50], timkiem[15];
	HOADON *a =(HOADON*)malloc (sizeof (HOADON) * n);
	//Nhap so san pham 
	do 
	{
		printf ("\nNhap so san pham(so san pham phai it hon 100): ");
		scanf ("%d",&n);
	}while (n < 0 || n > 100);
	 //Nhap san pham
	for (int i = 0; i < n; i++)
	{
		printf ("\nNhap san pham thu %d: ", i + 1);
		Nhap_HD(&a[i]);
	}
	//Xuat hoa don
	for (int i= 0; i < n; i++)
	{
		printf ("\nHoa don thu %d: ", i + 1);
		Xuat_HD(&a[i]);
	}
	//Tong gia tri hoa don
	printf ("\nTong gia tri hoa don la: %.3f",Tong_HD(a,n));
	//Mo file
	printf ("\nNhap duong dan can mo de ghi:");
	fflush(stdin);
	gets(path);
	FILE *fp = fopen (path,"wb");
	if (fp == NULL)
	{
		printf ("\nLoi mo file.");
	}
	else 
	{
		fwrite (a,sizeof(HOADON), n, fp);
		fclose (fp);
	}
	free (a);
	printf ("\nDa ghi vao file '%s' thanh cong:",path);
	//Doc file
	printf ("\nNhap duong dan can doc: ");
	fflush (stdin);
	gets(path);
	FILE *f = fopen (path,"rb");
	if (f == NULL)
	{
		printf ("\nLoi mo file.");
	}
	else 
	{
		HOADON *a1 = (HOADON*)malloc(sizeof(HOADON) * n);
		if (a1 == NULL) 
		{
            printf("Khong the cap phat bo nho.\n");
            fclose(f);
            free(a);
            return 1;
        }
		fread (a1, sizeof (HOADON), 1, f);
		fclose (f);
		for (int i= 0; i < n; i++)
		{
			printf ("\nHoa don thu %d: ", i + 1);
			Xuat_HD(&a1[i]);
		}
		//Tim ma don hang
		printf ("\nNhap ma hoa don can tim: ");
		fflush (stdin);
		gets (timkiem);
		Tim_HD(a1,n,timkiem);
		printf("\nDanh sach sau khi sap xep: ");
        Sap_giam(a1, n);
        Xuat_DSHD(a1, n);
		free(a1);	
	}
	free (a);
	return 0;
}
//Dinh nghia ham
void Nhap_HD (HOADON *a)
{
	//Nhap ma hoa don
	printf ("\nNhap ma hoa don: ");
	fflush (stdin);
	gets (a->maHD);
	//Nhap ten khach hang
	printf ("\nNhap ten khach hang: ");
	fflush (stdin);
	gets (a->tenKH);
	//Nhap ma san pham 
	printf ("\nNhap ma san pham: ");
	fflush (stdin);
	gets (a->maSP);
	//Nhap so luong
	printf ("\nNhap so luong: ");
	scanf ("%d",&a->soLuong);
	//Nhap gia san pham 
	printf ("\nNhap gia san pham: ");
	scanf ("%f",&a->gia);
	//Nhap ngay, thang, nam
	printf ("\nNhap ngay: ");
	scanf ("%d",&a->ngayHD.ngay);
	printf ("\nNhap thang: ");
	scanf ("%d",&a->ngayHD.thang);
	printf ("\nNhap nam: ");
	scanf ("%d",&a->ngayHD.nam);
}
void Xuat_HD (HOADON *a)
{
	a->thanhTien = a->soLuong * a->gia;
	printf ("\nMA hoa don	Ten khach hang		Ma san pham		So luong	Gia		Thanh tien		Ngay/Thang/Nam");
	printf ("\n %s		%s		%s			%d		%.3f 		%.3f		%d/%d/%d", a->maHD, a->tenKH, a->maSP, a->soLuong, a->gia, a->thanhTien, a->ngayHD.ngay, a->ngayHD.thang, a->ngayHD.nam);
}
float Tong_HD (HOADON a[], int n)
{
	float s = 0;
	for (int i = 0; i < n; i++)
	{
		s = s + a[i].thanhTien;
	}
	return s;
}
void Tim_HD (HOADON a[], int n, char t[])
{	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp (t,a[i].maHD) == 0)
		{
			dem ++;
			printf ("\nDon hang co ton tai.");
			Xuat_HD(&a[i]);
		} 
	}
		if (dem == 0)
	{
		printf ("\nMa don hang khong ton tai.");
	}
}
void Sap_giam (HOADON a[], int n)
{
	HOADON t;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].thanhTien < a[j].thanhTien)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}	
	}
}
void Xuat_DSHD (HOADON a[], int n)
{
	for (int i= 0; i < n; i++)
	{
		printf ("\nHoa don thu %d: ", i + 1);
		Xuat_HD(&a[i]);
	}
}
	



