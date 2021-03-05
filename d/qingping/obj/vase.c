//XXDER

inherit ITEM;
void create()
{
   set_name("白玉花瓶", ({ "vase" , "white vase", "花瓶" }) );
   set("no_shown", 1);
   set("no_get",1);
   set_weight(500);
   set_max_encumbrance(100);
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "in");
      set("unit", "个");
      set("long", "这是一个白玉花瓶，通体洁白无瑕。\n");
      set("value", 2000);
   }
}
int is_container() { return 1; }
