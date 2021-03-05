// book.c

inherit ITEM;

void create()
{
    set_name( "白玉琴", ({ "yaoqin", "qin" }));
    set_weight(5000);
    set("unit", "把");
    set("long", "这是一把用白玉做成的瑶琴，上面写着一些你不识的古篆字。\n");
    set("value", 5000);
    set("skill", ([
        "name":                 "jiayiforce",
        "exp_required": 5000,                
        "sen_cost":             40,     
        "difficulty":   50,            
        "max_skill":    10           
    ]) );
    ::init_item();
}
