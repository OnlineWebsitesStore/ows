<div class="container">
	<div class="row">
		<div ng-app="templates" ng-controller="TemplateController">
			<div class="col-sm-3">
				<?php print views_embed_view('taxonomy_categories', 'block_1'); ?>
			</div>
			<div class="col-sm-9">
				<div class="row">
					<div class="template col-lg-3 col-md-4 col-xs-6 thumb" ng-repeat="template in templates">
					  	<h2>{{template.title}}</h2>
					  	<img src="{{template.image}}" />
				 	</div>
			 	</div>
			</div>
            <div class="pagination-centered">
                <pagination total-items="totalItems" ng-model="currentPage" items-per-page="itemsPerPage" ng-change="pageChanged(currentPage)"></pagination>
            </div>
        </div>
	</div>
</div>

