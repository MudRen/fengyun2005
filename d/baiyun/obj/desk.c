//sinny
inherit ITEM;
void create()
{
   set_name("书案", ({ "书案","book desk","desk" }) );
   set_weight(5000);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "on");
      set("unit", "张");
      set("long", "这是一张书案，上面摆着几本线装典籍。\n");
      set("value", 1);
   }
}
int is_container() { return 1; }
