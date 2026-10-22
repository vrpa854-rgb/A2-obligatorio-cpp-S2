class MFSet {
    private:
        int *altura, *representantes, n;

    public:
        MFSet(int n) {
            representantes = new int[n];
            altura = new int[n];
            this->n = n;
            for (int i = 0; i < n; i++)
            {
                representantes[i] = i;
                altura[i] = 0;
            }
        }

        int find(int x) {
            if (representantes[x] != x) {
                representantes[x] = find(representantes[x]);
            }
            return representantes[x];
        }

        void merge(int x, int y)
        {
            int xRep = find(x);
            int yRep = find(y);

            if (xRep == yRep) return;

            if (altura[xRep] < altura[yRep]) {
                representantes[xRep] = yRep;
            } else if (altura[xRep] > altura[yRep]) {
                representantes[yRep] = xRep;
            } else {
                representantes[yRep] = xRep;
                altura[xRep] = altura[xRep] + 1;
            }
        }
};