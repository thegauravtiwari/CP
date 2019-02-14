package codeChef.LongOct2018;
import java.util.*;
import java.io.*;
public class BeautifulBricks {

	static int num=1000000007;
	public static void main(String[] args) {
		InputReader s=new InputReader(System.in);
		PrintWriter w=new PrintWriter(System.out);

		int t=s.nextInt();

		for(;t>0;t--)
		{
			int n=s.nextInt();
			int k=s.nextInt();
			
			int ans=find(n,k);
			w.println(ans);
		}
		w.close();
	}
	
	public static int find(int n,int k)
	{
		int f[][]=new int[2][k+1];
		int g[][]=new int[2][k+1];
		int bit=0;
		for(int i=0;i<=n;i++)
		{
			bit=i&1;
			for(int j=0;j<=k && j<=i;j++)
			{
				if(i==0 && j==0)
				{
					f[bit][j]=1;
					g[bit][j]=0;	
				}
				else if(j>i)
				{
					f[bit][j]=0;
					g[bit][j]=0;
				}
				else if(i==j)	
				{
					f[bit][j]=0;
					g[bit][j]=2;
				}
				else if(j==0)
				{
					f[bit][j]=1;
					g[bit][j]=0;
				}
				else
				{
					g[bit][j]=(2*f[1-bit][j-1]%num+g[1-bit][j-1]%num)%num;
					f[bit][j]=(f[1-bit][j]%num+g[1-bit][j]%num)%num;
				}
			}
		}
		return (f[bit][k]%num+g[bit][k]%num)%num;
	}
	
	static class InputReader {

		private final InputStream stream;
		private final byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public double nextDouble() //read double
		{
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			double res = 0;
			boolean dec = false;
			int count = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				if (dec)
					count--;
				res *= 10;
				res += c - '0';
				c = snext();
				if (c == '.') {
					if (!dec) {
						dec = true;
						c = snext();
					} else {
						throw new InputMismatchException();
					}
				}
			} while (!isSpaceChar(c));
			res *= Math.pow(10, count);
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			return a;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c)) {
				c = snext();
			}
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public String nextLine() { //considers space in same string
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isEndOfLine(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private boolean isEndOfLine(int c) {
			return c == '\n' || c == '\r' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}
