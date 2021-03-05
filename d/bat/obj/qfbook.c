//All Rights Reserved 1998 Apstone, Inc.

inherit ITEM;
void create()
{
 set_name("清风十三式", ({ "qing feng book" ,"book"}));
 set_weight(600);
 if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit", "本");
  set("long", "这是华山派中失传以久的一本剑谱。\n");
  set("value", 70);
  set("material", "wood");
  set("skill", ([
   "name":"sword",	
   "exp_required":1000,		
   "sen_cost":30,	
   "difficulty":20,	
   "max_skill":    59
  ]) );
 }
 ::init_item();
}
