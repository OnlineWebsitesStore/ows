var templates = angular.module('templates',[]);

templates.controller('TemplateController', function($scope, $http) {
  $scope.greeting = 'Hola!';

   $http.get('json/alltemplate/data').success(function(result){
   	$scope.templates = result;
   });

  $http.get('json/template/data').success(function(results){
  	$scope.templates_data = results;
  });
  
  $scope.setPage = function(tid, tid2) {
  	var getProperty = function (propertyName) {
    	return $scope.templates_data[propertyName];
	};
	$scope.templates = getProperty(tid);
  };

});

