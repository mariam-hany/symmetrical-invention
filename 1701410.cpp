#include<iostream>


#include<string>

#ifdef __GNUC__
# define __rdtsc __builtin_ia32_rdtsc
#else
# include<intrin.h>
#endif
using namespace std;
typedef unsigned long long u64;

u64  intial_permutation(u64 x) {            // test done
	
	int intial_permutation_given_matrix[64] = { 58,50,42,34,26,18,10,2
											  ,60,52,44,36,28,20,12,4
											  ,62,54,46,38,30,22,14,6
											  ,64,56,48,40,32,24,16,8
											  ,57,49,41,33,25,17, 9,1
											  ,59,51,43,35,27,19,11,3
											  ,61,53,45,37,29,21,13,5
											  ,63,55,47,39,31,23,15,7 };


	u64 out = 0;
	
	for (int i = 0; i < 64; ++i)
	{
		out |= (x >> (64 - intial_permutation_given_matrix[64 - 1 - i]) & 1) << i;

	}
	
	
	return out;
}

u64 inverse_permutation(u64 x) {         // test done
	

	int inverse_permutation_given_matrix[64] = { 40,8,48,16,56,24,64,32
												,39,7,47,15,55,23,63,31
												,38,6,46,14,54,22,62,30
												,37,5,45,13,53,21,61,29
												,36,4,44,12,52,20,60,28
												,35,3,43,11,51,19,59,27
												,34,2,42,10,50,18,58,26
												,33,1,41,9,49,17,57,25 };

	u64 out = 0;
	for (int i = 0; i < 64; ++i)
	{
		out |= (x >> (64 - inverse_permutation_given_matrix[64 - 1 - i]) & 1) << i;
		
	}
	return out;
}
u64 permutation_choice1(u64 x) {       // test done

	int permutation_choice1[56] = { 57,49,41,33,25,17, 9
									 , 1,58,50,42,34,26,18
									 ,10, 2,59,51,43,35,27
									 ,19,11, 3,60,52,44,36
									 ,63,55,47,39,31,23,15
									 , 7,62,54,46,38,30,22
									 ,14, 6,61,53,45,37,29
									 ,21,13, 5,28,20,12, 4
	};

	u64 out = 0;
	for (int i = 0; i < 56; ++i)
	{
		out |= (x >> ( 64 - permutation_choice1[56 - 1 - i]) & 1) << i;

	}
	return out;
}
u64 permutation_choice2(u64 x) {            // test done
	int permutation_choice2[48] = { 14,17,11,24, 1, 5
									, 3,28,15, 6,21,10
									,23,19,12, 4,26, 8
									,16, 7,27,20,13, 2
									,41,52,31,37,47,55
									,30,40,51,45,33,48
									,44,49,39,56,34,53
									,46,42,50,36,29,32

	};

	u64 out = 0;
	for (int i = 0; i < 48; ++i)
	{
		out |= (x >> (56 - permutation_choice2[48 - 1 - i]) & 1) << i;

	}
	return out;
}
u64 permutation(u64 x) {        //  test done              
	
	int permutation[32] = { 16, 7,20,21
							,29,12,28,17
							, 1,15,23,26
							, 5,18,31,10
							, 2, 8,24,14
							,32,27, 3, 9
							,19,13,30, 6
							,22,11, 4,25 };
	u64 out = 0;
	for (int i = 0; i < 32; ++i)
	{
		out |= (x >> (32 - permutation[32 - 1 - i]) & 1) << i;

	}
	return out;
}

u64  s_box(u64 x) {                     //test  done 
	
	int s_box[] = {     14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
							  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
							  4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
							  15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 ,

							 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
							  3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
							  0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
							  13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 ,

							 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
							  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
							  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
							  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 ,

							 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
							  13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
							  10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
							  3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 ,

							 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
							  14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
							  4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
							  11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 ,

							 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
							  10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
							  9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
							  4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 ,

							 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
							  13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
							  1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
							  6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 ,

							 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
							  1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
							  7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
							  2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11  };
	
	u64 result = 0;
	int idx;
	int *box;
	for (int i = 0; i <8; i++) {

		box = s_box + i * 64; //fetch the current S-box
		idx = x >> (7 - i) * 6 & 0x3F; //get the index
		idx = idx >> 1 & 15 | (idx & 1) << 4 | idx & 0x20;//reorder bits
		result |= ((u64)box[idx ]  )<< (7 - i) * 4;
		//cout << "  resulllllllllt " << result <<endl;
	}
	return result ;

}

u64 expansion(u64 x) {                       // test done
	int expansion[48] = { 32, 1, 2, 3, 4, 5
								, 4, 5, 6, 7, 8, 9
								, 8, 9,10,11,12,13
								,12,13,14,15,16,17
								,16,17,18,19,20,21
								,20,21,22,23,24,25
								,24,25,26,27,28,29
								,28,29,30,31,32, 1
	};
	u64 out = 0;
	for (int i = 0; i < 48; ++i)
	{
		out |= (x >> (32 - expansion[48 - 1 - i]) & 1) << i;

	}
	return out;
}
u64 read_u64_hex(const char*data) {
	u64 ret = 0;
	for (;; ++data) {
		unsigned char dec = *data - '0';
		if
			(dec < 10)
			ret = ret << 4 | dec;
		else {
			unsigned char upper = (*data & 0xDF) - 'A';

			if (upper > 5)
				break;
			ret = ret << 4 | upper + 10;

		}
	}
	return ret;
		}
u64 leftRotate(u64 n, unsigned int d)
{
	u64 b,m,a;
	//u64 m = (n << d) | (n >> (28 - d));
	//cout << "last two bits  " << (n >> (28 - d))<<endl;
	if (d == 1)
	{
		a = n << d;
		b = (n >> 27) &1;
		m =( a & (0xFFFFFFF)) | b;
	}
	if (d == 2)
	{
		a = n << d;
		b = (n >> 26) & 3;
		m = a & (0xFFFFFFF) |b;
	}
	return ( m);
}
u64 leftRotate2(u64 n, unsigned int d)
{
	u64 m;
	n = n << d;
	m = n >> 28;
	n |= m;
	n &= 0xFFFFFFF;

	return (n<<28)&(~0xFFFFFFF);
}
void bin(unsigned n)
{
	if (n > 1)
		bin(n >> 1);

	printf("%d", n & 1);
}
void bin1(long n)
{
	long i;
	cout << "0";
	for (i = 1 << 30; i > 0; i = i / 2)
	{
		if ((n & i) != 0)
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}
	}
}


void  generate_keys(u64 key, u64 *new_key) {
	
	u64 key_after_pc1 = permutation_choice1(key);
	//bin1(key_after_pc1);
	//u64 new_key[16];
	u64 k_left = (  key_after_pc1) >> 28;  // 00011 10010........> 00000 00011
	u64 k_right = (key_after_pc1 &0xFFFFFFF) ; // 00011 10010 ......> 10010 00000....> 00000 10010
	u64 key11, key22;
	 u64 key44, key33;
	int num_of_turns[16] = { 1,1,2,2,2,2,2,2
						   ,1,2,2,2,2,2,2,1 };
	
	for (int i = 0; i <16; i++) {
		key11 = leftRotate( k_left , num_of_turns[i]);      // when i do k1= left_shift_of_round(k1, i) 
		key22 = leftRotate(k_right , num_of_turns[i]);  
		
		key33 = (key11 << 28) | key22;	
		
		key44 = permutation_choice2(key33);
		
		new_key[i] = key44;
		
		k_left = key11;
		k_right = key22;

		

	}
}
void gen_keys_decrypt(u64 key, u64* genetated_keys, u64* gen_key2)
{


	generate_keys(key, genetated_keys);

	for (int i = 0; i < 16; i++)
	{
		gen_key2[i] = genetated_keys[15 - i];
	}
}

u64 encript(u64 data , u64 key[] ) {

	u64 d0, d, d1, d2, d3, d4,d00,d20;
	d0 = intial_permutation(data);
	u64 d_left = d0 >> 32;  // 00011 10010........> 00000 00011
	u64 d_right = (d0 & 0xFFFFFFFF); // 00011 10010 ......> 10010 00000....> 00000 10010

	for (int i = 0; i < 16; i++) {

		d = expansion(d_right);
		d00 = d ^ key[i];
		d1 = s_box(d00);
		d2 = permutation(d1);
		d20 = d2 ^ d_left;
		d_left = d20;
				u64  temp = d_right; //d1
				d_right = d_left;
				d_left = temp;
			
	
	}
	d3 = (d_right << 32) | d_left;
	
	d4 = inverse_permutation(d3);
	

	
	return d4;

}

int main(int argc, char **argv) {
	u64 gen_keys[16] = {};
	u64 gen_keys2[16] = {};

	string ciper_encript_decript  = argv[1];
	const char* plain = argv[2];
	const  char* key = argv[3];
	u64 data = read_u64_hex(plain);
	u64 key2 = read_u64_hex(key);
	if (ciper_encript_decript == "encrypt")
	{
		
		generate_keys(key2, gen_keys);
		long long t1 = __rdtsc();
		u64 cipher = encript(data, gen_keys);
		long long t2 = __rdtsc();
		printf("plain: %016llX\n", cipher);
		printf("Cycles: %lld\n", t2 - t1);



	}
	else if (ciper_encript_decript == "decrypt")
	{

		gen_keys_decrypt(key2, gen_keys, gen_keys2);
		long long t1 = __rdtsc();
		u64 plain =encript(data, gen_keys2);
		long long t2 = __rdtsc();
		printf("plain: %016llX\n", plain);
		printf("Cycles: %lld\n", t2 - t1);

	}
	return 0;
}
