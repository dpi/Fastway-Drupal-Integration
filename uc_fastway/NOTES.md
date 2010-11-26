These notes are planning for v2


Label database

Content Type: Fastway Label (fastwaylabel)

Per label:

* __str__  Label Name
* __str__  Label machine name (fastway internal)
* __str__  Origin Code machine name (fastway internal)
* __Bool__ _Preference_
**         Always quote Frequent price -- will purchase at Frequent rate when quantity reaches zero
**         Quote Standard price if there are there are 0 quantity of all label options
* __Int__  Minimum purchase order to qualify for Frequent purchase rate
* __Int__  Minimum purchase order to qualify for Standard purchase rate
* __Int__  Frequent cost per unit
* __Int__  Standard cost per unit
* __Int__  Shelf life of Frequent label (in seconds). 0 for never expire.
* __Int__  Shelf life of Standard label (in seconds). 0 for never expire.
* __Int__  Inventory of Frequent label remaining
* __Int__  Inventory of Standard label remaining
* __Int__  Maximum weight covered by label (in grams) current total
* __Int__  _Overflow label content type Drupal nid_
**         After the maximum weight has been reached for this label, which label can be applied next.
**         Leave 0 for no more.