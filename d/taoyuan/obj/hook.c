inherit ITEM;
#include <ansi.h>

void create()
{
    set_name("小钩子", ({ "hook" , "gou zi", "小钩子"}) );
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("long", "一个小小的钩子，看起来很象用来钓鱼的钩子，也许你可以用
它来做一个钓鱼杆。（ｍａｋｅ） \n");
        set("value", 10);
    }
    ::init_item();
}

void init()
{
   if(this_player()==environment())
   add_action("do_make", "make");
}

int do_make(string arg)
{
   int i,yxan=0,bamboo1=0;
   object fpole, me, xan, bamboo, *inv;

   me = this_player();
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
      if(inv[i]->query("name") == "鱼线") {yxan=1; xan = inv[i];}
      if(inv[i]->query("name") == "细竹竿") {bamboo1=1; bamboo = inv[i];}
   }
   if ( yxan && bamboo1)
   {
      destruct(xan);
      destruct(bamboo);
      fpole = new(__DIR__"fpole");
      fpole->move(me);
      message_vision("$N用灵巧的双手造成了一个别致的小鱼杆。\n", me);
      destruct(this_object());
   }
   else
      message_vision("$N摆弄着手里的鱼线。\n", me);
   return 1;
}




