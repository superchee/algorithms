
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

	int nAve = (nums1Size + nums2Size) / 2;
	int nLNums = 0, nPre = 0, nIdx1 = 0, nIdx2 = 0, nCurrent = 0;

	while (nLNums <= nAve) {
		nPre = nCurrent;
		if (nIdx1 < nums1Size && nIdx2 < nums2Size) {
			nCurrent = nums1[nIdx1] < nums2[nIdx2] ? nums1[nIdx1++] : nums2[nIdx2++];
		}
		else if (nIdx1 < nums1Size) {
			nCurrent = nums1[nIdx1++];
		}
		else {
			nCurrent = nums2[nIdx2++];
		}
		nLNums++;
	}

	if ((nums1Size + nums2Size) % 2) {
		return nCurrent;
	}
	else {
		return (nPre + nCurrent) / 2.0;
	}


}

double findMedianSortedArraysSecond(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	bool bOdd = (nums1Size + nums2Size) % 2;
	int nMid = (nums1Size + nums2Size) / 2;
	int nLNums = 0, nPre = 0, nIdx1 = 0, nIdx2 = 0, nCurrent = 0;

	while (nLNums <= nMid) {
		if (nIdx1 == nums1Size) {
			nPre = *(nums2 + nIdx2);
			nIdx2++;

		}
		else if (nIdx2 == nums2Size) {
			nPre = *(nums1 + nIdx1);
			nIdx1++;
		}
		else {
			if (*(nums1 + nIdx1) <= *(nums2 + nIdx2)) {
				nPre = *(nums1 + nIdx1);
				nIdx1++;
			}
			else {
				nPre = *(nums2 + nIdx2);
				nIdx2++;
			}
		}
		nLNums++;
	}

	if (bOdd) {
		if (nIdx1 == nums1Size) {
			return *(nums2 + nIdx2);
		}
		else if (nIdx2 == nums2Size) {
			return *(nums1 + nIdx1);
		}
		else {
			return *(nums1 + nIdx1) < *(nums2 + nIdx2) ? *(nums1 + nIdx1) : *(nums2 + nIdx2);
		}

	}
	else
	{
		if (nIdx1 == nums1Size) {
			return (*(nums2 + nIdx2) + nPre) / 2.0;
		}
		else if (nIdx2 == nums2Size) {
			return (*(nums1 + nIdx1) + nPre) / 2.0;
		}
		else {
			return *(nums1 + nIdx1) < *(nums2 + nIdx2) ? (*(nums1 + nIdx1) + nPre) / 2.0 : (*(nums2 + nIdx2) + nPre) / 2.0;
		}
	}

}