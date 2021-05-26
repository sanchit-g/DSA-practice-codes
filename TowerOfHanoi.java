import java.util.Scanner;

public class TowerOfHanoi {

	public static void solve(int n, int source, int auxiliary, int target) {

		if (n == 0)
			return;

		solve(n - 1, source, target, auxiliary);
		System.out.println(source + " " + target);
		solve(n - 1, auxiliary, source, target);
	}

	public static void main(String[] args) {

		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();

		double k = Math.pow(2, n) - 1;

		System.out.println((int) k);
		solve(n, 1, 2, 3);

		sc.close();
	}
}
