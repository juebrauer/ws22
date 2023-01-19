#include <iostream>
#include <vector>

template <typename T>
class hke_vector
{
    public:
    
    hke_vector(int initial_capacity)
    {
        data = (T*)malloc(initial_capacity * sizeof(T));
        capacity = initial_capacity;
        vec_size = 0;
    }


    void enlarge_array()
    {
        // Schaffe Platz für ein weiteres float
        data = (T*) realloc(data, sizeof(T)*(capacity+1));
        capacity += 1;
    }


    void push_back(T f)
    { 
        // Noch genügend Platz im Speicherblock?
        if (! (vec_size<capacity) )
            enlarge_array();

        // Speicher die Zahl f im Speicherblock ab
        data[vec_size] = f;
        vec_size++;
    }

    int find(T f)
    {
        int pos;
        for (pos=0; pos<vec_size; pos++)
        {
            if (data[pos] == f)
                return pos;
        }

        // Element f is not in data
        // For this, return -1 to signalize this
        return -1;
    }

    void remove(T f)
    {
        int pos = find(f);
        if (pos==-1)
        {
            std::cout << "Cannot remove element " << f << " since its not in the data.\n";
            return;
        }


        std::cout << "Found element " << f << " at pos=" << pos << "\n";
        for (int i=pos; i<vec_size-1; i++)
        {
            std::cout << "Moving one element to front\n";
            data[i] = data[i+1];
        }
        vec_size--;

    }


    void insert(int pos, T f)
    {
        // de Morgan:            NOT(   A    &&  B    ) = NOT(A) || NOT(B)
        //if ((vec_size==0) || ( !( (pos>=0) && (pos<=vec_size-1) ) ) )
        if ((vec_size==0) || ((pos<0) || (pos>vec_size-1)) )
        {
            std::cout << "Invalid position " << pos << " for inserting element!\n";
            return;
        }

        // 1. Vergrößere Array um ein Element
        if (vec_size == capacity)
            enlarge_array();

        // 2. Verschiebe Element ab Position pos
        for (int i=vec_size; i>=pos+1; i--)
        {
            std::cout << "Moving one element to back\n";
            data[i] = data[i-1];
        }

        // 3. Füge f jetzt an die freigewordene Stelle pos ein
        data[pos] = f;

        // 4. Vergesse nicht, die Anzahl der Elemente hoch zu zählen!
        vec_size++;

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

        T* data;
        uint capacity;
        uint vec_size;

};

template <typename T1, typename T2, typename T3>
T3 myMax(T1 a, T2 b)
{
    return (a>b)? a : b;
}

#include <string>

int main()
{
    
    std::cout << myMax<float,float,float>(3.4343,9.4343) << "\n";
    //std::cout << myMax('w', 'z') << "\n";
    //std::string s1 = "Hallo";
    //std::string s2 = "Guten Tag!";
    //std::cout << (s1 < s2) << "\n";
    //std::cout << myMax(s1,s2) << "\n";
    
    
    /*
    std::vector<std::string> v1;
    v1.push_back( "Uwe" );
    v1.push_back( "Jürgen" );
    v1.push_back( "Hans" );

    std::cout << "Mittleres Element im Vektor ist " << v1[v1.size()/2] << "\n";
    */    


   /*
   hke_vector<char> v1(3);
   
   v1.push_back( 'A' );   
   v1.push_back( 'B' );
   v1.push_back( 'C' );
   v1.push_back( 'D' );
   v1.info();

   v1.remove( 'B' );
   v1.info();
   

   v1.insert( 0, 'E' );
   v1.info();
   */
   

}