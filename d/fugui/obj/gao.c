inherit ITEM;
void create()
{
        set_name( "铁镐", ({"gao", "tie gao"}) );
        set_weight(800);
        set_max_encumbrance(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("prep", "on");
                set("long","一根约三尺多长的铁镐。\n");
                set("material", "iron");
        }
	::init_item();
}

void init()
{
        add_action("do_dig","dig");
}

int do_dig()
{
        object me,ob;
        me = this_player();
        ob = this_object();
        if( me->is_fighting() )
        	return notify_fail("在战斗中刨地，想找死吗！\n");
        if( me->is_busy() )
        	return notify_fail("你上一个动作还没有完成，不能刨地。\n");
	tell_object(me,"你掏出一把"+ob->name()+"，用力向地上刨去。\n");
    	environment(me)->dig_notify(ob,0);
    	return 1;
}
