#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
        set_name("小木牌子", ({ "sign"}) );     // 让这个id有别于其他东西。不使用单字id!
        set_weight(30000);
        set("unit", "个");
        set("desc", "一个小小的小木牌子，可以一次性写字（print）\n");
        set("no_get",1);
        set("no_sell",1);
        set("no_drop",1);
        set("no_stack",1);
        set("no_reset",1);
        set("item_type","p");
        set("lore_item",1);
        set("outdoors",1);
        set("size",0);
        set("value", 100000);
		set("tax",10);
		set("score_tax",1);
        seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_print","print");
}

int do_print(string arg)
{
        object obj, tarobj, tempobj;
        string sheet, target,color;
        object me = this_player(),env=environment(me),ob=this_object();

		if( !arg || sscanf(arg, "%s - %s %s", target,color,sheet)!=3 )
			return notify_fail("指令格式：print <目标> - <颜色> <文字>\n");
		
		if (present(target,env) != ob)
                return 0;
        if (!env->is_owner(me->query("id")))
                return notify_fail("屋子里的物件只有主人才能使用。\n");
        if (!CHINESE_D->check_chinese(sheet))
                return notify_fail("只有中文才适合题字耶．．．\n");
        if( strlen(sheet) > 40 ) {
                return notify_fail("牌子上的地方不够大，写不下这么多文字。\n");
        }
        sheet = color + sheet;
        sheet = replace_string(sheet, "$BLK$", BLK);
        sheet = replace_string(sheet, "$RED$", RED);
        sheet = replace_string(sheet, "$GRN$", GRN);
        sheet = replace_string(sheet, "$YEL$", YEL);
        sheet = replace_string(sheet, "$BLU$", BLU);
        sheet = replace_string(sheet, "$MAG$", MAG);
        sheet = replace_string(sheet, "$CYN$", CYN);
        sheet = replace_string(sheet, "$WHT$", WHT);
        sheet = replace_string(sheet, "$HIR$", HIR);
        sheet = replace_string(sheet, "$HIG$", HIG);
        sheet = replace_string(sheet, "$HIY$", HIY);
        sheet = replace_string(sheet, "$HIB$", HIB);
        sheet = replace_string(sheet, "$HIM$", HIM);
        sheet = replace_string(sheet, "$HIC$", HIC);
        sheet = replace_string(sheet, "$HIW$", HIW);
        sheet = replace_string(sheet, "$NOR$", NOR);
        sheet = sheet+NOR;

        if (me->query_skill("literate") == 150)
                message_vision(CYN"$N细心的在小木牌子上刻下＂"+sheet+CYN"＂。\n"NOR,me);
        else
                message_vision(CYN"$N歪歪扭扭的在小木牌子上刻下＂"+sheet+CYN"＂。\n"NOR,me);
        set("text",sheet);
        set("desc", "一个小小的小木牌子，牌子上刻着一行小字：\n"+query("text")+"\n");
        reset_item_list(env);
        return 1;
}

int restore_item()
{
        object item;
        mapping item_list,mitem;
        string *lists,str;
        int i,idx;

        item_list = environment()->query("stock_"+query("item_type"));
        if (!environment()->query("stock_"+query("item_type")+"/text"))
                return 1;
        // 没有任何文字。
        set("text",environment()->query("stock_"+query("item_type")+"/text"));
        set("desc", "一个小小的小木牌子，牌子上刻着一行小字：\n"+query("text")+"\n");
        return 1;
}

int reset_item_list(object dest)
{
        environment()->set("stock_"+query("item_type")+"/text",query("text"));
        environment()->save();
        return 1;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

