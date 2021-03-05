
inherit ITEM;

void create()
{
        set_name("棺材", ({ "coffin"}) );
        set_weight(500); 
	set_max_encumbrance(8000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "in");
                set("unit", "个");
                set("long", "这是一具很普通的杨木棺材，棺盖似乎还未盖上。\n");
                set("value", 1);
        }
}
int is_container() { return 1; }

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object cps;
    if(!arg="coffin"||!arg="棺盖") return 0;
        message_vision("$N推开棺材的盖子...\n",this_player());
    tell_object(this_player(),"你发现一具女子的尸骨，虽不是很漂亮，但看上去温柔朴实，\n令人暗自心惊的是女子虽死，但双目圆睁不闭。\n");
    if(present("corpse",this_object())) return 1;
    cps=new(__DIR__"lian_corpse");
    cps->move(this_object());
    return 1;
}
