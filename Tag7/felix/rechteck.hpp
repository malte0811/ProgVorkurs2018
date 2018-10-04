enum Dimension
{
    x_dim, // 0
    y_dim  // 1
};

class Rechteck
{
public:
    Rechteck(
        double x_min,
        double x_max,
        double y_min,
        double y_max);

    Rechteck(Rechteck const & other);
    void print() const;
    double get_min(Dimension dim) const;
    void set_min(double new_min, Dimension dim);
	double get_max(Dimension dim) const;
    void set_max(double new_max, Dimension dim);
    void compute_flaecheninhalt();
    
private:
    double _min[2];
    double _max[2];
    double _flaecheninhalt;
};
