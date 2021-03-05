inherit ITEM;

void create()
{
   set_name("红木书桌", ({ "desk" , "红木书桌", "书桌" }) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);

   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "on");
      set("unit", "张");
      set("long", "这是一张红木书桌，上面摆满了笔墨纸砚。\n");
      set("value", 1);
   }
}

int is_container() { return 1; }


