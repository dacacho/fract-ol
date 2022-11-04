#include <stdio.h>

void	main()
{
	for (float x = -1; x <= 1; x += 0.03125)
	{
		for (float y = -2; y <= 1; y += 0.03125)
		{
			float zy = y, zx = x;
			for (int n = 0; n < 31; n++)
			{
				float zz = zy * zy - zx * zx;
				zx = zy * zx * 2;
				zy = zz;
				zy += y;
				zx += x;
			}
			zx * zx + zy * zy < 4 ? printf("*") : printf(" ");
		}
		printf("\n");
	}
}
