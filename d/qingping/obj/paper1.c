
inherit ITEM;

void create()
{
        set_name("发黄了的纸", ({ "yellow paper", "paper", "纸"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张已经发黄了的纸，上面的字迹残缺不全，你隐约可辨
	桃源                   
                      宝藏    水井 
几个字。
\n");
                set("value", 1);
        }
}

void init()
{
   add_action("do_remember", "remember");
}

int do_remember(string arg)
{
   object me;

   me = this_player();

   if (!arg || (arg != "yellow paper" && arg != "发黄了的纸"))
      return 0;
   else {
      tell_object(me, "你嘴里嘟囔着桃源，宝藏，水井这几个字，并牢牢地记在了心里。\n");
      me->set_temp("marks/cangbao",1);
      return 1;
   }
   return 0; 
}
