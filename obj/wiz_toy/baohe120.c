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
         ob=new("/obj/generate/boots_150_20.c");
        ob->move(this_player());
        ob=new("/obj/generate/boots_150_10.c");
         ob->move(this_player());
       ob=new("/obj/generate/cloth1_150_19.c");
        ob->move(this_player());
       ob=new("/obj/generate/cloth3_150_9.c");
       ob->move(this_player());
      ob=new("/obj/generate/head_150_9.c");
       ob->move(this_player());
       ob=new("/obj/generate/head_150_19.c");
        ob->move(this_player());
       ob=new("/obj/generate/neck_150_9.c");
        ob->move(this_player());
       ob=new("/obj/generate/neck_150_19.c");
        ob->move(this_player());
       ob=new("/obj/generate/surcoat_150_9.c");
        ob->move(this_player());
       ob=new("/obj/generate/surcoat_150_23.c");
        ob->move(this_player());
       ob=new("/obj/generate/wrists_150_8.c");
        ob->move(this_player());
         me->add("potential",1200000);
       message_vision(HIR "\n$N打开宝盒，两眼发光，好多装备啊！\n" NOR,me);
       set("opened",1);
        return 1;
}
