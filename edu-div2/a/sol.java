
import java.io.*;
import java.util.*;
import java.lang.*;

import static java.lang.Math.*;

public class Main {
    static final int MAXN = 100001; // sqrt of 10^9 ;
    /*static ArrayList<Integer> arr =new ArrayList<>();*/
    static int int_max = Integer.MAX_VALUE;
    static int[] spf = new int[MAXN];

    public static void main(String[] args) throws IOException {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        while (t-- != 0) {
            int n = sc.nextInt();
            long k = sc.nextLong();
            long[] a = new long[n];
            long sum=0;
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
                sum+=a[i];
            }

            long count=0;
            for(int i=n-1;i>0;i--){
                sum-=a[i];
                long x=k*sum;
                long y=a[i]*100;
                if (y - x> 0) {
                    long d=(y-x)/k;
                    if((y - x )%k!=0)
                    {
                        d++;
                    }
                    count = max(count,d);
                }

            }

            System.out.println(count);

        }

    }


    static long power(long x, long y) {
        long res = 1;
        while (y > 0) {
            if ((y & 1) == 1)
                res = res * x;

            y = y >> 1; // y = y/2
            x = x * x;
        }
        return res;
    }

    static int fact(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i;
        return res;
    }

    static int ceilSearch(int arr[], int low, int high, int x) {
        int mid;

        if (x <= arr[low])
            return low;
        if (x > arr[high])
            return -1;

        mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x) {
            if (mid + 1 <= high && x <= arr[mid + 1])
                return mid + 1;
            else
                return ceilSearch(arr, mid + 1, high, x);
        } else {
            if (mid - 1 >= low && x > arr[mid - 1])
                return mid;
            else
                return ceilSearch(arr, low, mid - 1, x);
        }
    }

    static int floorSearch(int arr[], int low, int high, int x) {
        // If low and high cross each other
        if (low > high)
            return -1;

        // If last element is smaller than x
        if (x >= arr[high])
            return high;

        // Find the middle point
        int mid = (low + high) / 2;

        // If middle point is floor.
        if (arr[mid] == x)
            return mid;

        // If x lies between mid-1 and mid
        if (
                mid > 0 && arr[mid - 1] <= x && x < arr[mid])
            return mid - 1;

        // If x is smaller than mid, floor
        // must be in left half.
        if (x < arr[mid])
            return floorSearch(
                    arr, low,
                    mid - 1, x);

        // If mid-1 is not floor and x is
        // greater than arr[mid],
        return floorSearch(
                arr, mid + 1, high,
                x);
    }

    static void sieve() {
        spf[1] = 1;
        for (int i = 2; i < MAXN; i++)
            spf[i] = i;
        for (int i = 4; i < MAXN; i += 2)
            spf[i] = 2;

        for (int i = 3; i * i < MAXN; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAXN; j += i)
                    if (spf[j] == j)
                        spf[j] = i;
            }
        }
    } //spf

    static ArrayList<Integer> getFactorization(int x) {
        sieve();
        ArrayList<Integer> ret = new ArrayList<>();
        while (x != 1) {
            ret.add(spf[x]);
            x = x / spf[x];
        }
        return ret;
    }

    static ArrayList<Integer> sieveOfEratosthenes(int n) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        boolean prime[] = new boolean[n + 1];
        Arrays.fill(prime, true);
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (prime[i])
                arr.add(i);
        }
        return arr;
    }

    static boolean isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }

    static int funhelpfulforsegmented(int[] primes, int numprimes) {

        primes[numprimes++] = 2;

        for (int i = 3; i <= 32000; i += 2) {
            boolean isprime = true;
            double cap = Math.sqrt(i) + 1.0;

            for (int j = 0; j < numprimes; j++) {
                if (j >= cap) break;
                if (i % primes[j] == 0) {
                    isprime = false;
                    break;
                }
            }
            if (isprime) primes[numprimes++] = i;
        }
        return numprimes;
    }

    static ArrayList<Integer> segmentedsieve(int M, int N) {
        int[] primes = new int[4000];
        int numprimes = 0;
        numprimes = funhelpfulforsegmented(primes, numprimes);
        ArrayList<Integer> arr = new ArrayList<>();
        if (M < 2) M = 2;
        boolean[] isprime = new boolean[100001];
        for (int j = 0; j < 100001; j++) {
            isprime[j] = true;
        }

        for (int i = 0; i < numprimes; i++) {
            int p = primes[i];
            int start;

            if (p >= M) start = p * 2;
            else start = M + ((p - M % p) % p);

            for (int j = start; j <= N; j += p) {
                isprime[j - M] = false;
            }
        }
        for (int i = M; i <= N; i++) {
            if (isprime[i - M]) arr.add(i);
        }
        return arr;
    }

    static long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    public static int gcdExtended(int a, int b, int x, int y) {
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }

        int x1 = 1, y1 = 1;
        int gcd = gcdExtended(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return gcd;
    } // ax + by = gcd(a,b) ;
    // int gcd of a nd b is gcdExtended(a, b, x, y);

    static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    static void prime_upto_10pow8() {
        boolean[] prime = new boolean[100000000];
        Arrays.fill(prime, true);
        int i;
        prime[1] = false;
        prime[0] = false;
        for (i = 4; i < 100000000; i += 2)
            prime[i] = false;

        prime[2] = true;
        for (i = 3; i * i < 100000000; i += 2) {
            if (prime[i])
                for (int j = i * i; j > 0 && j < 100000000; j = j + (2 * i))
                    prime[j] = false;
        }
        int[] arr = new int[8000000];
        int j = 0;
        arr[0] = 2;
        int n = 100000000;
        for (i = 3; i <= n; i += 2) {
            if (prime[i])
                arr[++j] = i;
        }
        for (i = 1; i <= j; i += 100) {
            System.out.println(arr[i - 1]);
        }
    }

    public static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

}
