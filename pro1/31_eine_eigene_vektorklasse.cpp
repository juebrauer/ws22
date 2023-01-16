#include <iostream>
#include <vector>

class hke_vector
{
    public:
    
    hke_vector(int initial_capacity)
    {
        data = (float*)malloc(initial_capacity * sizeof(float));
        capacity = initial_capacity;
        vec_size = 0;
    }

    void push_back(float f)
    { 
        // Noch genügend Platz im Speicherblock?
        if (! (vec_size<capacity) )
        {
            // Schaffe Platz für ein weiteres float
            data = (float*) realloc(data, sizeof(float)*(capacity+1));
            capacity += 1;
        }

        // Speicher die Zahl f im Speicherblock ab
        data[vec_size] = f;
        vec_size++;
    }

    void remove(float f)
    {
        int pos;
        for (pos=0; pos<vec_size; pos++)
        {
            if (data[pos] == f)
                break;
        }
        std::cout << "Found element " << f << " at pos=" << pos << "\n";

        for (int i=pos; i<vec_size-1; i++)
        {
            data[i] = data[i+1];
        }

        vec_size--;

    }

    void info()
    {
        std::cout << "Current vector size: " << vec_size << "\n";
        for (int i=0; i<vec_size; i++)
        {
            std::cout << "Element #" << i  << ":" << data[i] << "\n";
        }
    }

    uint size()
    {
        return vec_size;
    }

    private:

        float* data;
        uint capacity;
        uint vec_size;

};

int main()
{
    /*
    std::vector<float> v1;
    v1.push_back( 3.32 );
    v1.push_back( 43.32 );
    v1.push_back( 5454.3 );

    std::cout << "Mittlere Zahl im Vektor ist " << v1[v1.size()/2] << "\n";
    */

   hke_vector v1(3);
   v1.push_back( 1.11 );
   v1.push_back( 2.22 );
   v1.push_back( 3.33 );
   v1.push_back( 4.44 );
   v1.info();

   v1.remove( 2.22 );
   v1.info();

}