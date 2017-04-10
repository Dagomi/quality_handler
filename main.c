#include <stdio.h>
#include <string.h>


char* quaility_hander (char *h_device, char *w_device, char *qualities_mpd){


	char buf[100]="";
	int i = 0;
	char *qualities[10];
	char *resolution_to_check[2];

	char *token_w,*token_h,*bw;
	int  with,height;
	int  with_device,device_height;
	int max_bw;
	//Loop variables
	int number_qualities = 0;
	int index_to_check = 0;
	//Print inputs
	printf("--Inputs--\n");
	with_device = atoi(w_device);
	device_height = atoi(h_device);
	printf( "%d\n", device_height );
	printf( "%d\n", with_device );
	printf( "%s\n", qualities_mpd );
	printf("------\n");

	//Copy quality to temp char
	memset(buf, '\0', sizeof(buf));
	strcpy(buf, qualities_mpd);
	char *p = strtok (buf, ",");

	//Parse qualities and obtain number of this
	while (p != NULL)
	{
		qualities[i++] = p;
		p = strtok (NULL, ",");
		number_qualities++ ;

	}
	printf ("Number of qualities %d\n", number_qualities);
	char *bitrate_to_check[number_qualities];
	//For debug
	printf("-----\n");
	printf("Print all qualities:\n");
	for (i = 0; i < number_qualities; ++i)
		printf("%s\n", qualities[i]);
	printf("-----\n");

	printf("Print all Bitrates:\n");
//	for (i = 0; i < number_qualities; ++i){
//		resolution_to_check[i] = strtok (qualities[i], "_");
//		bitrate_to_check[i] = strtok (NULL, "_");
//		printf( "resolution_to_check: %s\n", bitrate_to_check[i] );
//
//	}

	for (i = 0; i < number_qualities; ++i){
//		resolution_to_check[i] = strtok (qualities[i], "x");
//		bitrate_to_check[i] = strtok (NULL, "_");
//		token_w = strtok(resolution_to_check[i], "x");
//		token_h = strtok(NULL, "x");

		token_w = strtok (qualities[i], "x");
		token_h = strtok(NULL, "_");
		bitrate_to_check[i] = strtok (NULL, "_");
		with = atoi(token_w);
		height =atoi(token_h);

		printf("--Int--\n");
		printf( "With: %d\n", with );
		printf( "Height: %d\n", height );
		printf( "Bitrate to check: %s\n", bitrate_to_check[i] );

		printf("If: height_device %d <-> height %d \n", device_height,height );
		if (device_height >= height){
			printf("Bitrate to: %s\n", bitrate_to_check[i]);
			max_bw = bitrate_to_check[i];
			max_bw = i;
			printf("The quality IS supported.\n");
		}else{
			printf("The quality is NOT supported.\n");

		}
	}
	printf("Set max Bitrate to: %s\n", bitrate_to_check[max_bw]);
	return bitrate_to_check[max_bw];

}

int main ()
{

	char *h_device = "800";
	char *w_device = "600";
	char *qualities_mpd = "100x150.10,200x250_0.20,300x350_0.30,400x450_0.40";
	char *qualities_selected;
	qualities_selected = quaility_hander ( h_device,  w_device,  qualities_mpd);
	printf("Set max Bitrate to: %s\n", qualities_selected);
    return 0;
}
