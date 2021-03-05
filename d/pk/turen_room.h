
int alternative_die (object me)
{
  object ob;
  int i;
  string dir;

  
  if (!userp(me)) return 0;
 
  me->set("gin",1);
  me->set("kee",1);
  me->set("sen",1);
  me->set("eff_gin",me->query("max_gin"));
  me->set("eff_kee",me->query("max_kee"));
  me->set("eff_sen",me->query("max_sen"));
  me->clear_all_condition();
  me->remove_all_killer();
  all_inventory(environment(me))->remove_killer(me);
  ob = me->query_temp("last_damage_from");
  if(ob)
  	message_vision (WHT"\n$N被$n打成重伤，狼狈而逃！\n\n"NOR,me,ob);
  else
  	message_vision (WHT"\n$N身受重伤，狼狈而逃！\n\n"NOR,me);
  
     	me->move("/d/pk/ready");
  i = me->query("no_busy");
  me->delete("no_busy");
  me->start_busy(5);
  if(i)
  	me->set("no_busy",i);
  
  return 1;
}
