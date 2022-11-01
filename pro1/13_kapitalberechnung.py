def berechne_kapital_entwicklung(startkapital,
                                 zielkapital,
                                 zinsrate ) :
    kapital = startkapital
    jahr = 0
    while kapital<zielkapital :
        # nesting by indentation
        kapital = kapital * (1+zinsrate/100)
        jahr = jahr + 1
        print( f"Nach {jahr} Jahr hast du: {kapital:.2f}" )



#startkapital = float( input("Startkapital:") )
#zielkapital  = float( input("Zielkapital:") )
#zinsrate     = float( input("Zinsrate:") )

#berechne_kapital_entwicklung(startkapital, zielkapital, zinsrate)

def foo(a,b,c):
    return a+b+c

print( foo(1,2,3) )
print( foo(1.2, 2.21, 3.43) )
print( foo("ABC", "DEF", "GHI") )
print( foo( ["Croissants", "Mischbrot"],
            ["Bagel", "Brötchen"],
            [3, "Berliner"] ) )
zahl = int(input("Gib eine Zahl ein:"))
if zahl==42:
    print("Was für eine schöne Zahl!")
else:
    print("Es gibt schönere Zahlen!")







