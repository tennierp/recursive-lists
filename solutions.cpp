#include "reclists.hpp"
#include "solutions.hpp"

// Returns the number of nodes at the top-level of list p.
int numNodesAtTheTopLevel(list p) {
    if(is_null(p)) {
        return 0;
    }

    return 1 + numNodesAtTheTopLevel(cdr(p));
}

// Joins two lists end to end, producing a new list that contains all elements of the first list followed by all elements of the second
list append(list p, list q) {
    if (is_null(p))
        return q;

    return cons(car(p), append(cdr(p), q));
}

// Returns a new list with the elements of list p in the opposite order.
list reverse(list p) {
    if (is_null(p))
        return p;

    return append(reverse(cdr(p)), cons(car(p), null()));
}

// Takes a list (possibly empty) but not an atom and returns true if the list consists entirely of atoms.
bool is_lat(list p) {
    if (is_null(p)) {
        return true;
    }

    if (!is_atom(car(p))) {
        return false;
    }

    return is_lat(cdr(p));
}

// Searches for an atom p inside of list q and returns true if found, false if not found.
bool member(list p, list q) {
    if (is_null(q)) {
        return false;
    }

    if (is_atom(car(q))) {
        if (eq(p, car(q))) {
            return true;
        }
        return member(p, cdr(q));
    }

    return member(p, car(q)) || member(p, cdr(q));
}

//Takes a non-empty list (not an atom) and returns its last element.
list last(list p) {
    if (is_null(cdr(p))) {
        return car(p);
    }

    return last(cdr(p));
}

//Takes two lists of atoms of the same length and returns a list of pairs, where each pair contains corresponding atoms from p and q.
list list_pair(list p, list q) {
    if (is_null(p)) {
        return p;
    }

    return cons(cons(car(p), cons(car(q), null())), list_pair(cdr(p), cdr(q)));
}

//Takes as input a list whose elements are lists of atoms and returns a list of the first element from each sublist.
list firsts(list p) {
    if (is_null(p)) {
        return p;
    }

    return cons(car(car(p)), firsts(cdr(p)));
}

//Takes a list (not an atom) and returns a list in which all nested parentheses are removed (except the outer set).
list flat(list p) {
    if (is_null(p)) {
        return p;
    }

    if (is_atom(car(p))) {
        return cons(car(p), flat(cdr(p)));
    }

    return append(flat(car(p)), flat(cdr(p)));
}

//Takes two lists (not atoms) and returns true if p and q contain at least one atom in common.
bool two_the_same(list p, list q) {
    if(is_null(p)) {
        return false;
    }

    if (is_atom(car(p))) {
        return member(car(p), q) || two_the_same(cdr(p), q);
    }

    return two_the_same(car(p), q) || two_the_same(cdr(p), q);
}

//Takes two recursive lists and determines if they are identical: parentheses must match in structure and
// all atoms must be identical in name and position.
bool equal(list p, list q) {
    if (is_null(p) && is_null(q))
        return true;
    if (is_null(p) || is_null(q))
        return false;

    if (is_atom(car(p)) && is_atom(car(q))) {
        if (eq(car(p), car(q))) {
            return equal(cdr(p), cdr(q));
        }
        return false;
    }

    if (is_atom(car(p)) || is_atom(car(q))) {
        return false;
    }

    return equal(car(p), car(q)) && equal(cdr(p), cdr(q));
}

//Takes a recursive list and returns its mirror image.
list total_reverse(list p) {
    if (is_null(p)) {
        return p;
    }

    if (is_atom(car(p))) {
        return append(total_reverse(cdr(p)), cons(car(p), null()));
    }

    return append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
}

//Takes a recursive list (not an atom) and returns a recursive list that consists only of the parentheses structure of the original.
list shape(list p) {
    if (is_null(p)) {
        return p;
    }

    if (is_atom(car(p))) {
        return shape(cdr(p));
    }

    return cons(shape(car(p)), shape(cdr(p)));
}

//Takes two lists of distinct atoms (representing sets) and returns a list of atoms that appear in both p and q. The empty list represents the empty set.
list intersection(list p, list q) {
    if (is_null(p)) {
        return p;
    }

    if (member(car(p), q)) {
        return cons(car(p), intersection(cdr(p), q));
    }

    return intersection(cdr(p), q);
}

//Takes two lists of distinct atoms (representing sets) and returns a list of the union of p and q, without repetition.
list list_union(list p, list q) {
    if (is_null(p)) {
        return q;
    }

    if (member(car(p), q)) {
        return list_union(cdr(p), q);
    }

    return cons(car(p), list_union(cdr(p), q));
}

//Takes a list of atoms (atoms may repeat) and returns a copy of p with every occurrence of atom old replaced by atom new.
list substitute(list old_atom, list new_atom, list p) {
    if (is_null(p)) {
        return p;
    }

    if (eq(car(p), old_atom)) {
        return cons(new_atom, substitute(old_atom, new_atom, cdr(p)));
    }

    return cons(car(p), substitute(old_atom, new_atom, cdr(p)));
}

//Takes a list of atoms p and an atom q, and returns a list that does not contain q. All occurrences of q are removed.
list remove(list p, list q) {
    if (is_null(p)) {
        return p;
    }

    if (eq(car(p), q)) {
        return remove(cdr(p), q);
    }

    return cons(car(p), remove(cdr(p), q));
}

//Takes two lists (neither of which is an atom) and returns true if every atom in p also appears in q.
bool subset(list p, list q) {
    if (is_null(p)) {
        return true;
    }

    if (is_atom(car(p))) {
        if (member(car(p), q)) {
            return subset(cdr(p), q);
        }

        return false;
    }

    if (subset(car(p), q)) {
        return subset(cdr(p), q);
    }

    return false;
}