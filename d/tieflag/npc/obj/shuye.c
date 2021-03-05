
inherit ITEM;

void create()
{
        set_name("树叶", ({ "leaf"}) );
        set_weight(30);
       	set("real",1); 
	set("unit", "片");
	set("long", "一片树叶上面用针刺了几个字，鲁东崂山。\n");
    ::init_item();
}

