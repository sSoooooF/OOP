//  Programmer(s) : ������� �.�.  &   ��������� �.�.    
/////////////////////////////////////////////////////////////////////////
#define kmax  50
#define jmax  18
#define imax  16

unsigned char  image_buffer[kmax][jmax][imax];

unsigned char image[kmax][jmax][imax] = {


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    //  A
	0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,
	0,0,3,3,3,2,2,2,2,2,2,3,3,3,0,0,
	0,0,3,2,2,2,1,1,1,1,2,2,2,1,0,0,
	0,3,3,2,2,1,1,0,0,1,1,2,2,1,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,3,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,3,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // �
	0,0,3,3,3,3,3,3,3,3,3,3,3,3,0,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,1,1,1,1,1,1,1,1,1,1,0,0,
	0,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,1,3,3,3,3,3,3,3,3,3,0,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,1,1,1,1,1,1,1,1,2,1,0,
	0,3,2,2,2,1,0,0,0,0,0,0,3,2,1,0,
	0,3,2,2,2,1,0,0,0,0,0,0,3,2,1,0,
	0,3,2,2,2,1,3,3,3,3,3,3,3,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // �
	0,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,1,1,1,1,1,1,1,1,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,0,3,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,0,3,2,2,1,0,
	0,3,2,2,1,3,3,3,3,3,3,3,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,1,0,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,1,1,0,
	0,3,2,2,1,1,1,1,1,1,1,1,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,0,3,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,0,3,2,2,1,0,
	0,3,2,2,1,3,3,3,3,3,3,3,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,



	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,   //  �
	0,3,3,3,3,3,3,3,3,3,3,3,3,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,1,1,1,1,1,1,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,1,1,1,1,0,
	0,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,
	0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // �
	0,0,0,0,3,3,3,3,3,3,3,3,0,0,0,0,
	0,0,0,3,2,2,2,2,2,2,2,2,1,0,0,0,
	0,0,0,3,2,2,1,1,1,1,2,2,1,0,0,0,
	0,0,0,3,2,2,1,0,0,3,2,2,1,0,0,0,
	0,0,0,3,2,2,1,0,0,3,2,2,1,0,0,0,
	0,0,0,3,2,2,1,0,0,3,2,2,1,0,0,0,
	0,0,0,3,2,2,1,0,0,3,2,2,1,0,0,0,
	0,0,0,3,2,2,1,0,0,3,2,2,1,0,0,0,
	0,0,0,3,2,2,1,0,0,3,2,2,1,0,0,0,
	0,0,0,3,2,2,1,3,3,3,2,2,1,0,0,0,
	0,0,0,3,2,2,2,2,2,2,2,2,1,0,0,0,
	0,0,3,3,2,2,2,2,2,2,2,2,1,1,0,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,1,1,1,1,1,1,1,1,1,1,2,1,0,
	0,3,1,1,0,0,0,0,0,0,0,0,3,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,



	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // �
	0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,1,1,1,1,1,1,1,1,1,1,1,0,
	0,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,2,2,2,2,2,2,2,2,1,0,0,0,
	0,3,2,2,2,2,2,2,2,2,2,2,1,0,0,0,
	0,3,2,2,1,1,1,1,1,1,1,1,1,0,0,0,
	0,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,1,2,3,3,3,3,3,3,3,3,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,2,0,
	0,3,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,




	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // �
	3,0,0,0,0,0,3,3,3,0,0,0,0,0,3,0,
	3,3,0,0,0,0,3,2,1,0,0,0,0,3,1,0,
	3,2,3,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,2,3,0,0,3,2,1,0,0,3,2,2,1,0,
	0,1,2,2,3,0,3,2,1,0,3,2,2,1,0,0,
	0,0,1,2,2,3,3,2,1,3,2,2,1,0,0,0,
	0,0,0,1,2,2,3,2,1,2,2,1,0,0,0,0,
	0,0,0,0,1,2,2,2,2,2,1,0,0,0,0,0,
	0,0,0,0,0,1,2,2,2,1,0,0,0,0,0,0,
	0,0,0,0,3,2,3,2,1,2,1,0,0,0,0,0,
	0,0,0,3,2,2,3,2,1,2,2,1,0,0,0,0,
	0,0,3,2,2,1,3,2,1,1,2,2,1,0,0,0,
	0,3,2,2,1,0,3,2,1,0,1,2,2,1,0,0,
	3,2,2,1,0,0,3,2,1,0,0,1,2,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,1,2,1,0,
	3,1,0,0,0,0,3,2,1,0,0,0,0,1,1,0,
	1,0,0,0,0,0,3,1,1,0,0,0,0,0,1,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //  �
	0,0,0,3,3,3,3,3,3,3,3,3,1,0,0,0,
	0,0,3,2,2,2,2,2,2,2,2,2,2,1,0,0,
	0,3,2,2,2,1,1,1,1,1,2,2,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,2,2,2,2,1,0,
	0,3,2,2,1,1,0,0,0,3,2,2,2,1,0,0,
	0,0,0,0,0,0,0,0,3,2,2,1,0,0,0,0,
	0,0,0,0,0,0,3,2,2,2,2,2,1,0,0,0,
	0,0,0,0,0,0,3,1,1,1,1,2,2,1,0,0,
	0,0,0,0,0,0,0,0,0,0,1,2,2,1,0,0,
	0,3,3,3,3,2,0,0,0,0,0,3,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,0,3,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,0,3,2,2,1,0,
	0,0,2,2,1,1,2,2,3,3,3,3,2,1,0,0,
	0,0,0,2,2,2,2,2,2,2,2,2,1,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //  �
	0,3,3,3,3,1,0,0,0,0,3,3,3,3,3,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,3,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,3,3,3,2,2,2,1,0,
	0,3,2,2,2,1,0,3,3,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,0,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,1,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,1,1,1,1,1,0,0,0,0,3,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,



	0,0,0,0,0,0,3,1,2,3,0,0,0,0,0,0,  //  �
	0,3,3,3,3,1,0,1,1,0,3,3,3,3,3,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,3,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,3,3,3,2,2,2,1,0,
	0,3,2,2,2,1,0,3,3,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,0,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,1,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,1,1,1,1,1,0,0,0,0,3,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //  �
	0,3,3,3,3,3,0,0,0,3,3,3,3,3,0,0,
	0,3,2,2,2,1,0,0,3,2,2,2,1,0,0,0,
	0,3,2,2,2,1,0,3,2,2,2,1,0,0,0,0,
	0,3,2,2,2,1,3,2,2,2,1,0,0,0,0,0,
	0,3,2,2,2,2,2,2,2,1,0,0,0,0,0,0,
	0,3,2,2,2,2,2,2,1,0,0,0,0,0,0,0,
	0,3,2,2,2,2,2,2,1,0,0,0,0,0,0,0,
	0,3,2,2,2,2,2,2,2,1,0,0,0,0,0,0,
	0,3,2,2,2,2,2,2,2,2,1,0,0,0,0,0,
	0,3,2,2,2,1,1,2,2,2,2,1,0,0,0,0,
	0,3,2,2,2,1,0,3,2,2,2,2,1,0,0,0,
	0,3,2,2,2,1,0,0,3,2,2,2,2,1,0,0,
	0,3,2,2,2,1,0,0,0,3,2,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,1,1,1,1,0,0,0,0,0,3,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,     // �
	0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,
	0,0,3,3,3,2,2,2,2,2,2,3,3,3,0,0,
	0,0,3,2,2,2,1,1,1,1,2,2,2,1,0,0,
	0,3,3,2,2,1,1,0,0,1,1,2,2,1,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //  �
	3,3,3,3,2,0,0,0,0,0,0,3,3,3,3,2,
	3,2,2,2,1,0,0,0,0,0,0,3,3,2,2,1,
	3,2,2,2,1,1,0,0,0,0,3,3,2,2,2,1,
	3,2,2,2,1,1,2,0,0,3,3,3,2,2,2,1,
	3,2,2,2,1,1,2,2,3,3,3,3,2,2,2,1,
	3,2,2,2,1,1,2,2,3,3,3,3,2,2,2,1,
	3,2,2,2,1,1,1,1,2,3,1,3,2,2,2,1,
	3,2,2,2,1,0,1,1,2,1,0,3,2,2,2,1,
	3,2,2,2,1,0,0,1,1,0,0,3,2,2,2,1,
	3,2,2,2,1,0,0,0,0,0,0,3,2,2,2,1,
	3,2,2,2,1,0,0,0,0,0,0,3,2,2,2,1,
	3,2,2,2,1,0,0,0,0,0,0,3,2,2,2,1,
	3,2,2,2,1,0,0,0,0,0,0,3,2,2,2,1,
	3,2,2,2,1,0,0,0,0,0,0,3,2,2,2,1,
	1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,       // �
	0,3,3,3,3,1,0,0,0,0,3,3,3,3,3,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,1,3,3,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,3,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,3,3,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,2,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //  �
	0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,
	0,0,0,3,2,2,2,2,2,2,2,2,2,0,0,0,
	0,0,3,2,2,2,2,2,2,2,2,2,2,2,0,0,
	0,3,3,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,1,1,0,0,1,2,2,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,0,2,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,0,3,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,0,3,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,0,3,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,0,3,2,2,1,0,
	0,3,2,2,2,1,1,0,0,3,3,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,0,2,2,2,2,2,2,2,2,2,2,2,1,0,0,
	0,0,0,2,2,2,2,2,2,2,2,2,1,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,



	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,     // �
	0,3,3,3,3,3,3,3,3,3,3,3,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,1,1,1,1,1,1,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //  �
	0,3,3,3,3,1,1,2,2,3,3,3,1,0,0,0,
	0,3,2,2,2,1,1,2,2,2,2,2,2,1,0,0,
	0,3,2,2,2,1,1,1,2,2,2,2,2,2,1,0,
	0,3,2,2,2,1,1,1,1,1,1,2,2,2,1,0,
	0,3,2,2,2,1,1,0,0,0,1,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,0,2,2,2,1,0,
	0,3,2,2,2,1,1,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,1,1,2,3,3,3,2,2,1,0,
	0,3,2,2,2,1,1,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,1,1,2,2,2,2,2,2,1,0,0,
	0,3,2,2,2,1,1,1,1,1,1,1,1,0,0,0,
	0,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,2,1,0,0,0,0,0,0,0,0,0,0,
	0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //  �
	0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,
	0,0,0,3,2,2,2,2,2,2,2,2,2,0,0,0,
	0,0,3,2,2,2,2,2,2,2,2,2,2,2,0,0,
	0,3,3,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,1,1,0,0,1,2,2,2,2,1,0,
	0,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,1,0,0,0,0,0,0,0,0,0,0,0,
	0,3,2,2,2,1,1,0,0,3,3,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,0,2,2,2,2,2,2,2,2,2,2,2,1,0,0,
	0,0,0,2,2,2,2,2,2,2,2,2,1,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,     // �
	0,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,3,1,1,1,1,1,2,2,1,1,1,1,1,1,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // �
	0,3,3,3,3,0,0,0,0,0,3,3,3,3,0,0,
	0,3,2,2,1,0,0,0,0,0,3,2,2,1,0,0,
	0,3,2,2,1,0,0,0,0,0,3,2,2,1,0,0,
	0,3,2,2,1,3,3,3,3,3,3,2,2,1,0,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,1,0,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,1,0,0,
	0,3,1,1,1,1,1,1,1,1,1,2,2,1,0,0,
	0,0,0,0,0,0,0,0,0,0,3,2,2,1,0,0,
	0,0,0,0,0,0,0,0,0,0,3,2,2,1,0,0,
	0,3,3,3,1,0,0,0,0,0,3,2,2,1,0,0,
	0,3,2,2,1,0,0,0,0,0,3,2,2,1,0,0,
	0,3,2,2,1,3,3,3,3,3,3,2,2,1,0,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,1,0,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,1,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,     //  �
	0,0,0,0,0,0,3,3,3,1,0,0,0,0,0,0,
	0,0,3,3,3,3,3,3,3,1,1,2,2,2,0,0,
	0,3,2,2,2,2,3,2,2,1,1,2,2,2,1,0,
	3,2,2,1,1,1,3,2,2,1,1,1,2,2,2,1,
	3,2,2,1,0,0,3,2,2,1,0,0,3,2,2,1,
	3,2,2,1,0,0,3,2,2,1,0,0,3,2,2,1,
	3,2,2,1,0,0,3,2,2,1,0,0,3,2,2,1,
	3,2,2,2,1,2,3,2,2,1,1,2,2,2,2,1,
	0,2,2,2,2,2,3,2,2,1,1,2,2,2,1,0,
	0,0,2,2,2,2,3,2,2,1,1,1,1,1,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,3,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,



	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // �
	3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,
	1,2,2,2,3,1,0,0,0,0,3,3,2,2,2,1,
	0,1,2,2,2,3,1,0,0,3,3,2,2,2,1,0,
	0,0,1,2,2,2,3,1,3,3,2,2,2,1,0,0,
	0,0,0,1,2,2,2,3,2,2,2,2,1,0,0,0,
	0,0,0,0,1,2,2,2,2,2,2,1,0,0,0,0,
	0,0,0,0,0,1,2,2,2,2,1,0,0,0,0,0,
	0,0,0,0,0,0,1,2,2,1,0,0,0,0,0,0,
	0,0,0,0,0,3,2,2,2,2,1,0,0,0,0,0,
	0,0,0,0,3,2,2,2,2,2,2,1,0,0,0,0,
	0,0,0,3,2,2,2,2,2,2,2,2,1,0,0,0,
	0,0,3,2,2,2,1,1,1,2,2,2,2,1,0,0,
	0,3,2,2,2,1,0,0,0,3,3,2,2,2,1,0,
	3,2,2,2,1,0,0,0,0,0,3,3,2,2,2,1,
	3,1,1,1,0,0,0,0,0,0,0,3,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,       //  �
	0,3,3,3,3,1,0,0,0,0,3,3,3,3,3,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0,
	0,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0,
	0,3,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
	0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,
	0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,1,
	0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,1,



	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,       // �
	0,3,3,3,3,2,0,0,0,0,3,3,3,3,2,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,1,0,0,0,0,3,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,3,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,3,2,2,2,1,0,
	0,3,2,2,2,2,2,2,2,2,3,2,2,2,1,0,
	0,1,1,1,1,1,1,1,1,1,2,2,2,2,1,0,
	0,0,0,0,0,0,0,0,0,0,3,2,2,2,1,0,
	0,0,0,0,0,0,0,0,0,0,3,2,2,2,1,0,
	0,0,0,0,0,0,0,0,0,0,3,2,2,2,1,0,
	0,0,0,0,0,0,0,0,0,0,3,2,2,2,1,0,
	0,0,0,0,0,0,0,0,0,0,3,2,2,2,1,0,
	0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // �
	3,3,2,0,0,0,3,2,1,0,0,0,3,3,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,2,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,2,2,1,0,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0,
	3,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // �
	3,3,2,0,0,0,3,2,1,0,0,0,3,3,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,3,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,2,2,1,0,
	3,2,1,0,0,0,3,2,1,0,0,0,2,2,1,0,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0,
	3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,3,2,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,3,2,1,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,       // �
	3,3,3,3,3,3,2,0,0,0,0,0,0,0,0,0,
	3,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,
	1,1,1,2,2,2,1,0,0,0,0,0,0,0,0,0,
	0,0,0,2,2,2,1,0,0,0,0,0,0,0,0,0,
	0,0,0,3,2,2,1,2,2,3,3,3,3,3,0,0,
	0,0,0,3,2,2,1,1,2,2,2,2,2,2,1,0,
	0,0,0,3,2,2,1,1,2,2,2,2,2,2,1,0,
	0,0,0,3,2,2,1,1,1,1,1,1,2,2,1,0,
	0,0,0,3,2,2,1,0,0,0,0,1,2,2,1,0,
	0,0,0,3,2,2,1,0,0,0,0,1,2,2,1,0,
	0,0,0,3,2,2,1,0,0,0,0,2,2,2,1,0,
	0,0,0,3,2,2,1,1,1,2,2,2,2,2,1,0,
	0,0,0,3,2,2,1,1,2,2,2,2,2,2,1,0,
	0,0,0,3,2,2,1,1,2,2,2,2,2,2,1,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,





	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,   //  �
	3,3,3,3,3,0,0,0,0,0,0,3,3,3,3,3,
	3,2,2,2,1,0,0,0,0,0,0,3,2,2,2,1,
	3,2,2,2,1,0,0,0,0,0,0,3,2,2,2,1,
	3,2,2,2,1,0,0,0,0,0,0,3,2,2,2,1,
	3,2,2,2,1,1,2,2,2,0,0,3,2,2,2,1,
	3,2,2,2,2,2,2,2,2,2,0,3,2,2,2,1,
	3,2,2,2,2,2,2,2,2,1,0,3,2,2,2,1,
	3,2,2,2,1,1,1,2,2,1,0,3,2,2,2,1,
	3,2,2,1,0,0,0,2,2,1,0,3,2,2,2,1,
	3,2,2,1,0,0,0,2,2,1,0,3,2,2,2,1,
	3,2,2,1,0,0,0,2,2,1,0,3,2,2,2,1,
	3,2,2,2,2,2,2,2,2,1,0,3,2,2,2,1,
	3,2,2,2,2,2,2,2,2,1,0,3,2,2,2,1,
	3,2,2,2,2,2,2,2,2,1,0,3,2,2,2,1,
	1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,       // �
	0,0,0,3,3,3,2,0,0,0,0,0,0,0,0,0,
	0,0,0,3,2,2,1,0,0,0,0,0,0,0,0,0,
	0,0,0,3,2,2,1,0,0,0,0,0,0,0,0,0,
	0,0,0,3,2,2,1,0,0,0,0,0,0,0,0,0,
	0,0,0,3,2,2,1,2,2,3,3,3,3,3,0,0,
	0,0,0,3,2,2,1,1,2,2,2,2,2,2,1,0,
	0,0,0,3,2,2,1,1,2,2,2,2,2,2,1,0,
	0,0,0,3,2,2,1,1,1,1,1,1,2,2,1,0,
	0,0,0,3,2,2,1,0,0,0,0,1,2,2,1,0,
	0,0,0,3,2,2,1,0,0,0,0,1,2,2,1,0,
	0,0,0,3,2,2,1,0,0,0,0,2,2,2,1,0,
	0,0,0,3,2,2,1,1,1,2,2,2,2,2,1,0,
	0,0,0,3,2,2,1,1,2,2,2,2,2,2,1,0,
	0,0,0,3,2,2,1,1,2,2,2,2,2,2,1,0,
	0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,



	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // �
	0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,
	0,0,0,3,2,2,2,2,2,2,2,2,2,0,0,0,
	0,0,3,2,2,1,1,1,1,1,2,2,2,1,0,0,
	0,0,3,2,1,0,0,0,0,0,1,2,2,2,1,0,
	0,0,0,0,0,0,0,0,0,0,1,2,2,2,1,0,
	0,0,0,0,0,0,3,3,2,2,2,2,2,2,1,0,
	0,0,0,0,0,0,3,2,2,2,2,3,2,2,1,0,
	0,0,0,0,0,0,1,1,1,1,1,2,2,2,1,0,
	0,0,0,0,0,0,0,0,0,0,0,2,2,2,1,0,
	0,0,0,0,0,0,0,0,0,0,0,3,2,2,1,0,
	0,3,3,3,3,0,0,0,0,0,0,3,2,2,1,0,
	0,2,2,2,0,0,0,0,0,0,3,2,2,2,1,0,
	0,0,2,2,2,2,2,2,2,2,2,2,2,1,0,0,
	0,0,0,2,2,2,2,2,2,2,2,2,1,0,0,0,
	0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,



	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    //  �
	3,2,2,1,0,0,3,3,3,3,3,3,3,3,3,0,
	3,2,2,1,0,3,2,2,2,2,2,2,2,2,2,1,
	3,2,2,1,0,3,2,2,2,2,2,2,2,2,2,1,
	3,2,2,1,0,3,2,2,2,0,0,0,2,2,2,1,
	3,2,2,1,0,3,2,2,0,0,0,0,0,2,2,1,
	3,2,2,1,0,3,2,2,0,0,0,0,0,2,2,1,
	3,2,2,1,1,3,2,2,0,0,0,0,0,2,2,1,
	3,2,2,1,1,3,2,2,0,0,0,0,0,2,2,1,
	3,2,2,1,1,3,2,2,0,0,0,0,0,2,2,1,
	3,2,2,1,1,3,2,2,0,0,0,0,0,2,2,1,
	3,2,2,1,0,3,2,2,0,0,0,0,0,2,2,1,
	3,2,2,1,0,3,2,2,2,0,0,0,2,2,2,1,
	3,2,2,1,0,3,2,2,2,2,2,2,2,2,2,1,
	3,2,2,1,0,3,2,2,2,2,2,2,2,2,2,1,
	1,1,1,1,0,3,1,1,1,1,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,


	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,     // �
	0,0,0,0,3,3,3,3,3,3,2,3,3,2,1,0,
	0,0,0,3,2,2,2,2,2,2,2,2,2,2,1,0,
	0,0,3,2,2,2,2,2,2,2,2,2,2,2,1,0,
	0,0,3,2,2,2,2,1,1,1,1,1,2,2,1,0,
	0,0,3,2,2,2,1,0,0,0,0,3,2,2,1,0,
	0,0,3,2,2,2,1,0,0,0,0,3,2,2,1,0,
	0,0,3,2,2,2,1,0,0,0,0,3,2,2,1,0,
	0,0,0,1,2,2,2,3,3,3,3,3,2,2,1,0,
	0,0,0,0,1,1,2,2,2,2,1,3,2,2,1,0,
	0,0,0,0,0,0,1,2,2,2,1,3,2,2,1,0,
	0,0,0,0,0,3,2,2,2,1,0,3,2,2,1,0,
	0,0,0,0,3,2,2,2,1,0,0,3,2,2,1,0,
	0,0,0,3,2,2,2,1,0,0,0,3,2,2,1,0,
	0,0,3,2,2,2,1,0,0,0,0,3,2,2,1,0,
	0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,




	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // .
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,



	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    // 
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0


};

/////////////////////////////////////////////////////////////////////////
#define kmaxr  4
#define jmaxr  16
#define imaxr  16

unsigned char  imager_buffer[kmaxr][jmaxr][imaxr];
unsigned char imager[kmaxr][jmaxr][imaxr] = {

	1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       //  ������ 0
	1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0,
	1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0,
	1, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
	1, 2, 2, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 2, 1, 0, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,

	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   // ������ 1
	2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,
	2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
	2, 0, 0, 0, 2, 0, 2, 2, 0, 0, 0, 2, 0, 0, 0, 0,
	2, 0, 0, 2, 0, 0, 0, 0, 2, 2, 0, 0, 2, 0, 0, 0,
	2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 2, 0, 0,
	2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0,
	2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2,


};

//////////////////////////////////////////////////////////////////

