/*   0 1 2 3 4
A = [1,2,3,4,5]

0 1 2 3 4
1 2 3 4 5

0 1 2 3
1 2 4 5
count = 0

pref_even = [0, 1, 1, 4, 4]
pref_odd = [0, 0, 2, 2, 6]

suff_even = [8,8,5,5,0]
suff_odd = [6,4,4,0,0]

for(int i = 0 ; i < n ; i++)
{
    // removing this index
    odd = 0, even = 0;
    odd = pref_odd[i];
    odd+=even_suff[i];

    even = pref_even[i];
    even += odd_suff[i];
    if(odd==even) count++;
}
return count;
*/