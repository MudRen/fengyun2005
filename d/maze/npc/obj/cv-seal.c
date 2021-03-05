inherit ITEM;

void create()
{
	set_name("辟邪灵符", ({"seal"}) );
	set_weight(5);
	set("long",
		"这是丁乘风用法力写成的一张护身的三清符咒（burn）。\n");
	set("unit", "张");
        set("value", 0);
        set("fast_grab",1);
}


void init()
{
	add_action("do_burn", "burn");
}

int do_burn(string arg)
{
	string sheet, dest;
	object sobj;
	if( !arg || sscanf(arg, "%s", sheet)!=1 )
		return notify_fail("指令格式：burn <符咒>\n");
	if( !objectp(sobj = present(sheet, this_player()))) 
	        return notify_fail("你要使用哪张符咒？\n");
	if( this_player()->is_busy())
		return notify_fail("你现在没空烧符。\n");
	if(environment(this_player())->query("no_magic"))
           	return notify_fail("这里不可以用符咒。\n");
        if (query("paper_owner")!=this_player())
        	return notify_fail("这张符对你毫无作用。\n");
	message_vision("\n$N忽地一声将辟邪灵符点燃了起来。\n",this_player());
	tell_object(this_player(),"一股青烟袅袅升起，瞬间散去。。。。\n");
	
	if (REWARD_D->riddle_check(this_player(),"智毁血池")==1)
		REWARD_D->riddle_set(this_player(),"智毁血池",2);
	destruct(this_object());
	return 1;
}
