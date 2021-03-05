inherit ITEM;
void create()
{
    	set_name("头颅骨", ({ "skull"}) );
    	set_weight(500);
    	set_max_encumbrance(1000);
		set("skull",1);
    	set("recovered",1);
    	if( clonep() )
    		set_default_object(__FILE__);
    	else {
        	set("unit", "个");
        	set("long", "
一个头颅骨，头骨百汇穴的地方插着一根七寸长的铁钉。铁钉从头发里
全部插入脑内，如果不是头颅骨的眼睛已经烂掉，真的没法发现此人的
死因。头颅上的肌肤虽然已经全部腐烂，却被人用粘土补齐，依稀看出
是武当的老掌门七星子。\n");
        	set("value", 1);
    	}
    	::init_item();
}

// int is_container() { return 1; }




