inherit ITEM;

void create()
{
   set_name("木桌", ({ "table", "desk", "大木桌", "桌子" }) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);

   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "on");
      set("unit", "张");
      set("long", "这是一张大木桌，上面铺了一张雪白的台布。\n");
      set("value", 1);
   }
    ::init_item();
}

int is_container() { return 1; }


