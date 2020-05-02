// Linked-list selection sort

link listselection(link h)
{
    link max = NULL;
    link t = NULL; 
    link out = NULL;
    
    while (h->next != NULL){
        max = findmax(h);
        t = max->next;
        max->next = t->next;
        t->next = out;
        out = t;
    }
    h->next = out;
    return(h);
}