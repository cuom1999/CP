for f in *.cpp; do
    mv -- "$f" "$(basename -- "$f" .cpp).h"
done
