#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "宝盒" NOR, ({ "bao he" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "iron");
            set("long", "一个宝盒。\n");
        

          }
    ::init_item();
} 
void init()
{ 
        if(environment()==this_player())
                add_action("do_open","open");
} 
int do_open(string arg)
{
        object gold, me,ob;
        me = this_player();
        if(arg != "bao he" && arg != "宝盒") return 0;
        if(query("opened"))
                return notify_fail("你打开宝盒，但里面是空的！\n");
         ob=new("/obj/generate/boots_55_15.c");
        ob->move(this_player());
        ob=new("/obj/generate/boots_55_5.c");
         ob->move(this_player());
       ob=new("/obj/generate/cloth2_55_4.c");
        ob->move(this_player());
       ob=new("/obj/generate/cloth2_55_14.c");
       ob->move(this_player());
      ob=new("/obj/generate/head_55_4.c");
       ob->move(this_player());
       ob=new("/obj/generate/head_55_14.c");
        ob->move(this_player());
       ob=new("/obj/generate/neck_55_4.c");
        ob->move(this_player());
       ob=new("/obj/generate/neck_55_14.c");
        ob->move(this_player());
       ob=new("/obj/generate/surcoat_55_4.c");
        ob->move(this_player());
       ob=new("/obj/generate/surcoat_55_16.c");
        ob->move(this_player());
       ob=new("/obj/generate/wrists_55_3.c");
        ob->move(this_player());
         me->add("potential",40000);
       message_vision(HIR "\n$N打开宝盒，两眼发光，好多装备啊！\n" NOR,me);
       set("opened",1);
        return 1;
}
