## Project 2 - Recursive Lists

## Student Information
Parker Tennier  
ID: 008768156  
https://github.com/tennierp/recursive-lists.git

## Collaboration & Sources
Dr. Ali A. Kooshesh provided an Abstract Data Type of Recursive Lists including null(), is_null(), is_atom(), eq(), car(), cdr(),
cons(), write_list(), read_list(), and append(). With his ADT and functions I was able to develop 15 additional in depth
functions for the Recursive Lists ADT.

## Implementation Details
Recursive Lists are an ADT designed to learn more about recursion in C++. Each list is either an atom or a list (which may
itself be empty or contain nested lists). The functions I implemented use recursion to traverse and manipulate these
lists, returning either a new list or a boolean result.

Each function demonstrates a different recursive pattern:
- Some functions transform lists, such as `reverse`, `flat`, and `total_reverse`.
- Others perform structural checks, such as `is_lat`, `equal`, or `subset`.
- Several implement set-like behavior on lists of atoms, such as `intersection` and `list_union`.
- There are also functions such as `substitute` and `remove` that will do just as they sound, substitute an atom for another
or completely remove an atom from the provided list.

For example:
- `bool subset(list p, list q)` checks if every atom in `p` also appears in `q`.
- `list substitute(list old_atom, list new_atom, list p)` returns a copy of `p` with every occurrence of `old_atom` replaced
  by `new_atom`.

## Testing & Status
All 15 functions compile and run correctly when tested under their specified contracts. Each function assumes certain
input rules. Some functions require two lists of atoms, others require a single atom and a list. If these contracts are not
met, the functions may fail or produce undefined results. For example, `substitute` expects an atom for `old_atom`
and an atom for `new_atom`, while `list_pair` requires two lists of equal length.
