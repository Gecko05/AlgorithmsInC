// Non recursive Breadth-first search

void traverse(int k, void (*visit)(int))
{
    link t;
    QUEUEinit(V);
    QUEUEput(k);
    while (!QUEUEempty()){
        if (visited[k = QUEUEget()] == 0){
            (*visit)(k);
            visited[k] = 1;
            for (t = adj[k]; t != NULL; t = t->next){
                if (visited[t->v] == 0){
                    QUEUEput(t->v);
                }
            }
        }
    }
}